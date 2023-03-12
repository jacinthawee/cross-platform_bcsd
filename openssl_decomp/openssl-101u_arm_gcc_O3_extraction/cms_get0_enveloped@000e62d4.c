
ASN1_OBJECT * cms_get0_enveloped(ASN1_OBJECT **param_1)

{
  int iVar1;
  
  iVar1 = OBJ_obj2nid(*param_1);
  if (iVar1 != 0x17) {
    ERR_put_error(0x2e,0x83,0x6b,"cms_env.c",0x4f);
    return (ASN1_OBJECT *)0x0;
  }
  return param_1[1];
}

