
undefined4 * get_encryption_params(ASN1_OBJECT *param_1)

{
  int *piVar1;
  int iVar2;
  undefined4 *puVar3;
  char *s;
  undefined4 *puVar4;
  
  if (param_1 == (ASN1_OBJECT *)0x0) {
    s = (char *)get_gost_engine_param();
    if ((s == (char *)0x0) || (*s == '\0')) {
      return (undefined4 *)PTR_DAT_0011c178;
    }
    iVar2 = OBJ_txt2nid(s);
    if (iVar2 == 0) {
      ERR_GOST_error(0x67,0x6b,"gost_crypt.c",0x90);
      return (undefined4 *)0x0;
    }
  }
  else {
    iVar2 = OBJ_obj2nid(param_1);
  }
  if (PTR_GostR3411_94_CryptoProParamSet_00195a94 == (undefined *)0x0) {
LAB_0011c12e:
    ERR_GOST_error(0x67,0x6a,"gost_crypt.c",0x9c);
    puVar3 = (undefined4 *)0x0;
  }
  else {
    puVar4 = &gost_cipher_list;
    if (gost_cipher_list == iVar2) {
      return &gost_cipher_list;
    }
    do {
      puVar3 = puVar4 + 3;
      if (puVar4[4] == 0) goto LAB_0011c12e;
      piVar1 = puVar4 + 3;
      puVar4 = puVar3;
    } while (*piVar1 != iVar2);
  }
  return puVar3;
}

