
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

X509_VERIFY_PARAM * X509_VERIFY_PARAM_new(void)

{
  X509_VERIFY_PARAM *pXVar1;
  uint uVar2;
  uint uVar3;
  
  pXVar1 = (X509_VERIFY_PARAM *)CRYPTO_malloc(0x20,"x509_vpm.c",0x5b);
  pXVar1->name = (char *)0x0;
  pXVar1->policies = (stack_st_ASN1_OBJECT *)0x0;
  uVar2 = 0;
  uVar3 = (uint)&pXVar1->check_time & 0xfffffffc;
  do {
    *(undefined4 *)(uVar3 + uVar2) = 0;
    uVar2 = uVar2 + 4;
  } while (uVar2 < ((int)pXVar1 + (0x20 - uVar3) & 0xfffffffc));
  pXVar1->name = (char *)0x0;
  pXVar1->purpose = 0;
  pXVar1->trust = 0;
  pXVar1->inh_flags = 0;
  pXVar1->flags = 0;
  pXVar1->depth = -1;
  if ((_STACK *)pXVar1->policies != (_STACK *)0x0) {
    sk_pop_free((_STACK *)pXVar1->policies,ASN1_OBJECT_free);
    pXVar1->policies = (stack_st_ASN1_OBJECT *)0x0;
  }
  return pXVar1;
}

