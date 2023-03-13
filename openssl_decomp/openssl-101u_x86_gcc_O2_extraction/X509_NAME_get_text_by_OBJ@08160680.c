
int X509_NAME_get_text_by_OBJ(X509_NAME *name,ASN1_OBJECT *obj,char *buf,int len)

{
  _STACK *p_Var1;
  size_t sVar2;
  int iVar3;
  ASN1_OBJECT **ppAVar4;
  int iVar5;
  void *pvVar6;
  size_t __n;
  int iVar7;
  
  if (name != (X509_NAME *)0x0) {
    p_Var1 = (_STACK *)name->entries;
    iVar3 = sk_num(p_Var1);
    if (0 < iVar3) {
      iVar7 = 0;
      do {
        ppAVar4 = (ASN1_OBJECT **)sk_value(p_Var1,iVar7);
        iVar5 = OBJ_cmp(*ppAVar4,obj);
        if (iVar5 == 0) {
          if (iVar7 < 0) {
            return -1;
          }
          iVar3 = sk_num((_STACK *)name->entries);
          if ((iVar7 < iVar3) &&
             (pvVar6 = sk_value((_STACK *)name->entries,iVar7), pvVar6 != (void *)0x0)) {
            sVar2 = **(size_t **)((int)pvVar6 + 4);
            __n = len - 1;
            if ((int)sVar2 < len) {
              __n = sVar2;
            }
            if (buf != (char *)0x0) {
              memcpy(buf,(void *)(*(size_t **)((int)pvVar6 + 4))[2],__n);
              buf[__n] = '\0';
              return __n;
            }
            return sVar2;
          }
          do {
            invalidInstructionException();
          } while( true );
        }
        iVar7 = iVar7 + 1;
      } while (iVar3 != iVar7);
    }
  }
  return -1;
}

