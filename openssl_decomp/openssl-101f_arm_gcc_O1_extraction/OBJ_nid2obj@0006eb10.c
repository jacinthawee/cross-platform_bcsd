
ASN1_OBJECT * OBJ_nid2obj(int n)

{
  int iVar1;
  ASN1_OBJECT *pAVar2;
  undefined4 local_28;
  undefined *local_24;
  undefined auStack_20 [8];
  int local_18;
  
  if ((uint)n < 0x398) {
    iVar1 = n;
    if (n != 0) {
      pAVar2 = *(ASN1_OBJECT **)(&DAT_00140f90 + n * 0x18);
      iVar1 = n * 2;
      if (pAVar2 == (ASN1_OBJECT *)0x0) {
        iVar1 = 0x12a;
        goto LAB_0006eb76;
      }
    }
    pAVar2 = (ASN1_OBJECT *)(&nid_objs + (iVar1 + n) * 2);
  }
  else {
    if (added == (_LHASH *)0x0) {
      return (ASN1_OBJECT *)0x0;
    }
    local_24 = auStack_20;
    local_28 = 3;
    local_18 = n;
    pAVar2 = (ASN1_OBJECT *)lh_retrieve(added,&local_28);
    if (pAVar2 != (ASN1_OBJECT *)0x0) {
      return (ASN1_OBJECT *)pAVar2->ln;
    }
    iVar1 = 0x13b;
LAB_0006eb76:
    ERR_put_error(8,0x67,0x65,"obj_dat.c",iVar1);
  }
  return pAVar2;
}

