
char * PKCS12_get_friendlyname(PKCS12_SAFEBAG *bag)

{
  _STACK *p_Var1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  int *piVar4;
  char *pcVar5;
  int iVar6;
  
  p_Var1 = (_STACK *)bag->attrib;
  if (p_Var1 != (_STACK *)0x0) {
    for (iVar6 = 0; iVar3 = sk_num(p_Var1), iVar6 < iVar3; iVar6 = iVar6 + 1) {
      ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var1,iVar6);
      iVar3 = OBJ_obj2nid(*ppAVar2);
      if (iVar3 == 0x9c) {
        iVar6 = sk_num((_STACK *)ppAVar2[2]);
        if (iVar6 == 0) {
          return (char *)0x0;
        }
        piVar4 = (int *)sk_value((_STACK *)ppAVar2[2],0);
        if (piVar4 == (int *)0x0) {
          return (char *)0x0;
        }
        if (*piVar4 != 0x1e) {
          return (char *)0x0;
        }
        pcVar5 = OPENSSL_uni2asc((uchar *)((int *)piVar4[1])[2],*(int *)piVar4[1]);
        return pcVar5;
      }
    }
  }
  return (char *)0x0;
}

