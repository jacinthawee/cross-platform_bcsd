
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

BIGNUM * BN_get0_nist_prime_224(void)

{
  return (BIGNUM *)_bignum_nist_p_224;
}
