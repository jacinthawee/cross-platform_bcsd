
undefined4 alg_print(undefined4 param_1,ASN1_OBJECT **param_2)

{
  PBEPARAM *a;
  long lVar1;
  int n;
  char *pcVar2;
  int in_GS_OFFSET;
  uchar *local_14;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_14 = (uchar *)param_2[1]->ln[2];
  a = d2i_PBEPARAM((PBEPARAM **)0x0,&local_14,(long)*param_2[1]->ln);
  if (a != (PBEPARAM *)0x0) {
    lVar1 = ASN1_INTEGER_get(a->iter);
    n = OBJ_obj2nid(*param_2);
    pcVar2 = OBJ_nid2ln(n);
    BIO_printf(bio_err,"%s, Iteration %ld\n",pcVar2,lVar1);
    PBEPARAM_free(a);
  }
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return 1;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

