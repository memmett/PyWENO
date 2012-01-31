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

    ('f',     'in')  : ('__global const double *f, int n, int fsi', ''),
    ('sigma', 'in')  : ('__global const double *sigma, int ssi, int ssr', ''),
    ('omega', 'in')  : ('__global const double *omega, int wsi, int wsl, int wsr', ''),
    ('sigma', 'out') : ('__global double *sigma, int ssi, int ssr', ''),
    ('omega', 'out') : ('__global double *omega, int wsi, int wsl, int wsr', ''),
    ('fs',    'out') : ('__global double *fr, int frsi, int frsl', ''),

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

    ('f',     'in')  : ('f, n', 'real(8), intent(in) :: f(n)\ninteger, intent(in) :: n'),
    ('sigma', 'in')  : ('sigma', 'real(8), intent(in) :: sigma(n,0:{rmax})'),
    ('omega', 'in')  : ('omega', 'real(8), intent(in) :: omega(n,{n},0:{rmax},2)'),
    ('sigma', 'out') : ('sigma', 'real(8), intent(out) :: sigma(n,0:{rmax})'),
    ('omega', 'out') : ('omega', 'real(8), intent(out) :: omega(n,{n},0:{rmax},2)'),
    ('fs',    'out') : ('fr', 'real(8), intent(out) :: fr(n,0:{n}-1)'),

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
