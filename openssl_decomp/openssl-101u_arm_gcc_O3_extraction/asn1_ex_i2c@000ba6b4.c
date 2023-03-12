
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  int iVar1;
  uchar **ppuVar2;
  uchar *__src;
  int *piVar3;
  ASN1_BIT_STRING *pAVar4;
  size_t __n;
  code *pcVar5;
  uchar *local_24;
  uchar local_20 [12];
  
  local_24 = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar5 = *(code **)((int)it->funcs + 0x18), pcVar5 != (code *)0x0)) {
    iVar1 = (*pcVar5)();
    return iVar1;
  }
  if (it->itype == '\0') {
    iVar1 = it->utype;
    if (iVar1 != 1) {
      piVar3 = (int *)*pval;
      if (piVar3 == (int *)0x0) {
        return -1;
      }
LAB_000ba6ee:
      if (iVar1 == -4) {
        pval = (ASN1_VALUE **)(piVar3 + 1);
        iVar1 = *piVar3;
        *putype = iVar1;
        goto LAB_000ba6f4;
      }
    }
    iVar1 = *putype;
  }
  else {
    piVar3 = (int *)*pval;
    if (piVar3 == (int *)0x0) {
      return -1;
    }
    if (it->itype != '\x05') {
      iVar1 = it->utype;
      goto LAB_000ba6ee;
    }
    iVar1 = piVar3[1];
    *putype = iVar1;
  }
LAB_000ba6f4:
  switch(iVar1) {
  case 1:
    pAVar4 = (ASN1_BIT_STRING *)*pval;
    if (pAVar4 == (ASN1_BIT_STRING *)0xffffffff) {
      return -1;
    }
    if (it->utype != -4) {
      if (pAVar4 == (ASN1_BIT_STRING *)0x0) {
        if (it->size == 0) {
          return -1;
        }
      }
      else if (0 < it->size) {
        return -1;
      }
    }
    local_20[0] = (uchar)pAVar4;
    __src = local_20;
    __n = 1;
    if (cont == (uchar *)0x0) {
      return 1;
    }
    goto LAB_000ba762;
  case 2:
  case 10:
    ppuVar2 = (uchar **)cont;
    if (cont != (uchar *)0x0) {
      ppuVar2 = &local_24;
    }
    iVar1 = i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,ppuVar2);
    return iVar1;
  case 3:
    ppuVar2 = (uchar **)cont;
    if (cont != (uchar *)0x0) {
      ppuVar2 = &local_24;
    }
    iVar1 = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,ppuVar2);
    return iVar1;
  default:
    pAVar4 = (ASN1_BIT_STRING *)*pval;
    if ((it->size == 0x800) && (pAVar4->flags << 0x1b < 0)) {
      if (cont != (uchar *)0x0) {
        pAVar4->data = cont;
        pAVar4->length = 0;
        return -2;
      }
      return -2;
    }
    __src = pAVar4->data;
    __n = pAVar4->length;
    break;
  case 5:
    __n = 0;
    __src = (uchar *)0x0;
    break;
  case 6:
    __src = (uchar *)((ASN1_BIT_STRING *)*pval)[1].length;
    __n = ((ASN1_BIT_STRING *)*pval)->flags;
  }
  if ((cont == (uchar *)0x0) || (__n == 0)) {
    return __n;
  }
LAB_000ba762:
  memcpy(cont,__src,__n);
  return __n;
}

