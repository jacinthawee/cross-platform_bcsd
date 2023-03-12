
int i2d_PKCS8PrivateKey_nid_fp
              (FILE *fp,EVP_PKEY *x,int nid,char *kstr,int klen,undefined1 *cb,void *u)

{
  int iVar1;
  int iVar2;
  
  iVar1 = (*(code *)PTR_BIO_new_fp_006a835c)(fp,0);
  if (iVar1 != 0) {
    iVar2 = do_pk8pkey(iVar1,x,1,nid,0,kstr,klen,cb,u);
    (*(code *)PTR_BIO_free_006a7f70)(iVar1);
    return iVar2;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(9,0x7d,7,"pem_pk8.c",0xd9);
  return 0;
}

