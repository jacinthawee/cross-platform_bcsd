
BIO * cms_DigestAlgorithm_init_bio(X509_ALGOR *param_1)

{
  int iVar1;
  char *name;
  EVP_MD *parg;
  BIO_METHOD *type;
  BIO *bp;
  long lVar2;
  int in_GS_OFFSET;
  int line;
  ASN1_OBJECT *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  X509_ALGOR_get0(&local_14,(int *)0x0,(void **)0x0,param_1);
  iVar1 = OBJ_obj2nid(local_14);
  name = OBJ_nid2sn(iVar1);
  parg = EVP_get_digestbyname(name);
  if (parg == (EVP_MD *)0x0) {
    line = 0x173;
    iVar1 = 0x95;
  }
  else {
    type = BIO_f_md();
    bp = BIO_new(type);
    if (bp != (BIO *)0x0) {
      lVar2 = BIO_ctrl(bp,0x6f,0,parg);
      if (lVar2 == 0) {
        ERR_put_error(0x2e,0x74,0x77,"cms_lib.c",0x17a);
        BIO_free(bp);
        bp = (BIO *)0x0;
      }
      goto LAB_0818c4a9;
    }
    line = 0x17a;
    iVar1 = 0x77;
  }
  ERR_put_error(0x2e,0x74,iVar1,"cms_lib.c",line);
  bp = (BIO *)0x0;
LAB_0818c4a9:
  if (local_10 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return bp;
}

