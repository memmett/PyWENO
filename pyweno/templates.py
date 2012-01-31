"""PyWENO code generation templates."""


templates = {

  'c': {

    'sigma': 'sigma[i*ssi+{r}*ssr]',
    'omega': 'omega[i*wsi+{l}*wsl+{r}*wsr+{s}]',
    'fs':    'fr[i*frsi+{l}*frsl]',

    ('f',     'in')  : ('const double *restrict f, int n, int fsi', ''),
    ('sigma', 'in')  : ('const double *restrict sigma, int ssi, int ssr', ''),
    ('omega', 'in')  : ('const double *restrict omega, int wsi, int wsl, int wsr', ''),
    ('sigma', 'out') : ('double *restrict sigma, int ssi, int ssr', ''),
    ('omega', 'out') : ('double *restrict omega, int wsi, int wsl, int wsr', ''),
    ('fs',    'out') : ('double *restrict fr, int frsi, int frsl', ''),

    'callable': '''
      void {function}({args})
      {{
        int i;
        double {variables};
        for (i={k}-1; i<n-{k}+1; i++) {{
          {kernel}
        }}
      }}
      ''',

    },

  'opencl': {

    'sigma': 'sigma[i*ssi+{r}*ssr]',
    'omega': 'omega[i*wsi+{l}*wsl+{r}*wsr+{s}]',
    'fs':    'fr[i*frsi+{l}*frsl]',

    'callable': '''
      __kernel void {function}({args})
      {{
        int i = get_global_id(0);
        double {variables};
        {kernel}
      }}
      ''',

    },

  'fortran': {

    'sigma': 'sigma(i,{r})',
    'omega': 'omega(i,{l},{r},{s})',
    'fs':    'fr(i,{l})',

    'callable': '''
      subroutine {function}({args})
        implicit none
        {defs}

        do i={k}, n-{k}
          {kernel}
        end do
      end subroutine
    ''',

    },
  }
