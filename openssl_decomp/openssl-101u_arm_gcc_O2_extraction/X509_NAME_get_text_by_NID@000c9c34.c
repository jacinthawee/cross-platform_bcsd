
int X509_NAME_get_text_by_NID(X509_NAME *name,int nid,char *buf,int len)

{
  ASN1_OBJECT *b;
  int iVar1;
  ASN1_OBJECT **ppAVar2;
  int iVar3;
  void *pvVar4;
  size_t sVar5;
  size_t *psVar6;
  int iVar7;
  size_t __n;
  _STACK *p_Var8;
  
  b = OBJ_nid2obj(nid);
  if ((b != (ASN1_OBJECT *)0x0) && (name != (X509_NAME *)0x0)) {
    p_Var8 = (_STACK *)name->entries;
    iVar1 = sk_num(p_Var8);
    if (0 < iVar1) {
      iVar7 = 0;
      do {
        ppAVar2 = (ASN1_OBJECT **)sk_value(p_Var8,iVar7);
        iVar3 = OBJ_cmp(*ppAVar2,b);
        if (iVar3 == 0) {
          iVar1 = sk_num((_STACK *)name->entries);
          if ((iVar7 < iVar1) &&
             (pvVar4 = sk_value((_STACK *)name->entries,iVar7), pvVar4 != (void *)0x0)) {
            psVar6 = *(size_t **)((int)pvVar4 + 4);
          }
          else {
            psVar6 = (size_t *)0x0;
          }
          sVar5 = *psVar6;
          __n = sVar5;
          if (len <= (int)sVar5) {
            __n = len - 1;
          }
          if (buf == (char *)0x0) {
            return sVar5;
          }
          memcpy(buf,(void *)psVar6[2],__n);
          buf[__n] = '\0';
          return __n;
        }
        iVar7 = iVar7 + 1;
      } while (iVar7 != iVar1);
    }
  }
  return -1;
}

