module nonuniform
  use iso_c_binding
contains

  subroutine reconstruct(f, nn, beta, varpi, ll, kk, fr)
    use iso_c_binding
    implicit none

    integer(c_int), intent(in), value :: nn, nl, nk
    real(c_double), intent(in)  :: f(nn), beta(nn,ll,kk,kk), varpi(nn,ll,kk)
    real(c_double), intent(out) :: fr(nn,ll)

    integer(c_int) :: i, j, r, l, m, n
    real(c_double) :: sigma(kk,kk), omega(ll,kk), fr(ll,kk)

    ! loop over cells
    do i = 1, nn

       ! loop over reconstruction points
       do l = 1, ll

          ! smoothness indicators
          sigma = 0.0d0
          do m = 1, kk
             do n = 1, kk

             end do
          end do

          ! weights


          ! reconstructions


          ! weighted reconstruction

       end do
    end do
  end subroutine reconstruct

end module nonuniform
