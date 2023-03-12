
/* WARNING: Unknown calling convention -- yet parameter storage is locked */

DH * DH_new(void)

{
  undefined *puVar1;
  DH *dh;
  ENGINE *e;
  DH_METHOD *pDVar2;
  uint uVar3;
  int iVar4;
  _func_1704 *p_Var5;
  
  dh = (DH *)(*(code *)PTR_CRYPTO_malloc_006a8108)(0x4c,"dh_lib.c",0x7c);
  if (dh == (DH *)0x0) {
    ERR_put_error(5,0x69,0x41,"dh_lib.c",0x7f);
    return (DH *)0x0;
  }
  if (default_DH_method == (DH_METHOD *)0x0) {
    default_DH_method = DH_OpenSSL();
  }
  dh->meth = default_DH_method;
  e = ENGINE_get_default_DH();
  dh->engine = e;
  if (e == (ENGINE *)0x0) {
    pDVar2 = dh->meth;
  }
  else {
    pDVar2 = ENGINE_get_DH(e);
    dh->meth = pDVar2;
    if (pDVar2 == (DH_METHOD *)0x0) {
      ERR_put_error(5,0x69,0x26,"dh_lib.c",0x96);
      ENGINE_finish(dh->engine);
      goto LAB_00517f0c;
    }
  }
  puVar1 = PTR_CRYPTO_new_ex_data_006a9430;
  uVar3 = pDVar2->flags;
  dh->pad = 0;
  dh->version = 0;
  dh->p = (BIGNUM *)0x0;
  dh->g = (BIGNUM *)0x0;
  dh->length = 0;
  dh->pub_key = (BIGNUM *)0x0;
  dh->priv_key = (BIGNUM *)0x0;
  dh->q = (BIGNUM *)0x0;
  dh->j = (BIGNUM *)0x0;
  dh->seed = (uchar *)0x0;
  dh->seedlen = 0;
  dh->counter = (BIGNUM *)0x0;
  dh->method_mont_p = (BN_MONT_CTX *)0x0;
  dh->references = 1;
  dh->flags = uVar3 & 0xfffffbff;
  (*(code *)puVar1)(8,dh,&dh->ex_data);
  p_Var5 = dh->meth->init;
  if (p_Var5 == (_func_1704 *)0x0) {
    return dh;
  }
  iVar4 = (*p_Var5)(dh);
  if (iVar4 != 0) {
    return dh;
  }
  if (dh->engine != (ENGINE *)0x0) {
    ENGINE_finish(dh->engine);
  }
  (*(code *)PTR_CRYPTO_free_ex_data_006a9414)(8,dh,&dh->ex_data);
LAB_00517f0c:
  (*(code *)PTR_CRYPTO_free_006a7f88)(dh);
  return (DH *)0x0;
}

