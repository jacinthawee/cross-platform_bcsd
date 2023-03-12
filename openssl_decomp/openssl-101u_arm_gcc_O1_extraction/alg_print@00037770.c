
undefined4 alg_print(undefined4 param_1,ASN1_OBJECT **param_2)

{
  BIO *bio;
  PBEPARAM *a;
  int n;
  char *pcVar1;
  long lVar2;
  uchar *local_14;
  
  local_14 = (uchar *)param_2[1]->ln[2];
  a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_14,(long)*param_2[1]->ln);
  bio = bio_err;
  if (a != (PBEPARAM *)0x0) {
    n = OBJ_obj2nid(*param_2);
    pcVar1 = OBJ_nid2ln(n);
    lVar2 = ASN1_INTEGER_get(a->iter);
    BIO_printf(bio,"%s, Iteration %ld\n",pcVar1,lVar2);
    PBEPARAM_free(a);
  }
  return 1;
}

