
int * get_encryption_params(ASN1_OBJECT *param_1)

{
  int iVar1;
  char *s;
  int *piVar2;
  int *piVar3;
  
  if (param_1 == (ASN1_OBJECT *)0x0) {
    s = (char *)get_gost_engine_param(0);
    if (s == (char *)0x0) {
      return (int *)(gost_cipher_list + 0xc);
    }
    if (*s == '\0') {
      return (int *)(gost_cipher_list + 0xc);
    }
    iVar1 = OBJ_txt2nid(s);
    if (iVar1 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x97);
      return (int *)0x0;
    }
  }
  else {
    iVar1 = OBJ_obj2nid(param_1);
  }
  if (gost_cipher_list._4_4_ != 0) {
    if (iVar1 == gost_cipher_list._0_4_) {
      return (int *)gost_cipher_list;
    }
    piVar2 = (int *)gost_cipher_list;
    while (piVar3 = piVar2 + 3, piVar2[4] != 0) {
      piVar2 = piVar3;
      if (iVar1 == *piVar3) {
        return piVar3;
      }
    }
  }
  ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0xa0);
  return (int *)0x0;
}

