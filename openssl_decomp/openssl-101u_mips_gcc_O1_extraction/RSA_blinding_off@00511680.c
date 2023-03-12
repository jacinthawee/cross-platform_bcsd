
void RSA_blinding_off(RSA *rsa)

{
  if (rsa->blinding != (BN_BLINDING *)0x0) {
    (*(code *)PTR_BN_BLINDING_free_006a8728)();
    rsa->blinding = (BN_BLINDING *)0x0;
  }
  rsa->flags = rsa->flags & 0xfffffff7U | 0x80;
  return;
}

