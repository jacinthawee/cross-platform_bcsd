
int asn1_ex_i2c(ASN1_VALUE **pval,uchar *cont,int *putype,ASN1_ITEM *it)

{
  code *pcVar1;
  ASN1_BIT_STRING *pAVar2;
  size_t sVar3;
  uchar **ppuVar4;
  int *piVar5;
  uchar *__src;
  int iVar6;
  size_t __n;
  int in_GS_OFFSET;
  uchar *local_20 [3];
  uchar local_11;
  int local_10;
  
  local_10 = *(int *)(in_GS_OFFSET + 0x14);
  local_20[0] = cont;
  if ((it->funcs != (void *)0x0) &&
     (pcVar1 = *(code **)((int)it->funcs + 0x18), pcVar1 != (code *)0x0)) {
    sVar3 = (*pcVar1)(pval,cont,putype,it);
    goto LAB_08147cbd;
  }
  if (it->itype != '\0') {
    piVar5 = (int *)*pval;
    if (piVar5 != (int *)0x0) {
      if (it->itype != '\x05') {
        iVar6 = it->utype;
        goto LAB_08147cf1;
      }
      iVar6 = piVar5[1];
      *putype = iVar6;
      goto LAB_08147d02;
    }
LAB_08147dd0:
    sVar3 = 0xffffffff;
    goto LAB_08147cbd;
  }
  iVar6 = it->utype;
  if (iVar6 != 1) {
    piVar5 = (int *)*pval;
    if (piVar5 == (int *)0x0) goto LAB_08147dd0;
LAB_08147cf1:
    if (iVar6 == -4) {
      iVar6 = *piVar5;
      pval = (ASN1_VALUE **)(piVar5 + 1);
      *putype = iVar6;
      goto LAB_08147d02;
    }
  }
  iVar6 = *putype;
LAB_08147d02:
  switch(iVar6) {
  default:
    pAVar2 = (ASN1_BIT_STRING *)*pval;
    if ((it->size == 0x800) && ((*(byte *)&pAVar2->flags & 0x10) != 0)) {
      if (cont == (uchar *)0x0) {
        sVar3 = 0xfffffffe;
      }
      else {
        pAVar2->data = cont;
        pAVar2->length = 0;
        sVar3 = 0xfffffffe;
      }
      break;
    }
    __src = pAVar2->data;
    __n = pAVar2->length;
    goto LAB_08147d48;
  case 1:
    pAVar2 = (ASN1_BIT_STRING *)*pval;
    if (pAVar2 == (ASN1_BIT_STRING *)0xffffffff) goto LAB_08147dd0;
    if (it->utype != -4) {
      if (pAVar2 == (ASN1_BIT_STRING *)0x0) {
        if (it->size == 0) goto LAB_08147dd0;
      }
      else if (0 < it->size) goto LAB_08147dd0;
    }
    local_11 = (uchar)pAVar2;
    __n = 1;
    __src = &local_11;
    sVar3 = 1;
    if (cont == (uchar *)0x0) break;
    goto LAB_08147e1d;
  case 2:
  case 10:
    ppuVar4 = local_20;
    if (cont == (uchar *)0x0) {
      ppuVar4 = (uchar **)0x0;
    }
    sVar3 = i2c_ASN1_INTEGER((ASN1_INTEGER *)*pval,ppuVar4);
    break;
  case 3:
    ppuVar4 = local_20;
    if (cont == (uchar *)0x0) {
      ppuVar4 = (uchar **)0x0;
    }
    sVar3 = i2c_ASN1_BIT_STRING((ASN1_BIT_STRING *)*pval,ppuVar4);
    break;
  case 5:
    sVar3 = 0;
    break;
  case 6:
    __src = (uchar *)((ASN1_BIT_STRING *)*pval)[1].length;
    __n = ((ASN1_BIT_STRING *)*pval)->flags;
LAB_08147d48:
    sVar3 = __n;
    if ((cont != (uchar *)0x0) && (sVar3 = 0, __n != 0)) {
LAB_08147e1d:
      memcpy(cont,__src,__n);
      sVar3 = __n;
    }
  }
LAB_08147cbd:
  if (local_10 == *(int *)(in_GS_OFFSET + 0x14)) {
    return sVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

