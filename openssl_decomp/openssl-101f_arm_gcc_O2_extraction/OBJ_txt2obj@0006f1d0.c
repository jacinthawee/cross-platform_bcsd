
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  uint uVar1;
  int iVar2;
  int num;
  uchar *ptr;
  ASN1_OBJECT *pAVar3;
  uchar *local_38;
  uchar **local_34;
  uchar *local_30 [2];
  uint local_28;
  
  if ((no_name == 0) && ((uVar1 = OBJ_sn2nid(s), uVar1 != 0 || (uVar1 = OBJ_ln2nid(s), uVar1 != 0)))
     ) {
    if (uVar1 < 0x398) {
      iVar2 = 0x12a;
      pAVar3 = *(ASN1_OBJECT **)(&DAT_00140f94 + uVar1 * 0x18);
      if (pAVar3 != (ASN1_OBJECT *)0x0) {
        return (ASN1_OBJECT *)(&nid_objs + uVar1 * 6);
      }
    }
    else {
      if (added == (_LHASH *)0x0) {
        return (ASN1_OBJECT *)0x0;
      }
      local_34 = local_30;
      local_38 = (uchar *)0x3;
      local_28 = uVar1;
      pAVar3 = (ASN1_OBJECT *)lh_retrieve(added,&local_38);
      if (pAVar3 != (ASN1_OBJECT *)0x0) {
        return (ASN1_OBJECT *)pAVar3->ln;
      }
      iVar2 = 0x13b;
    }
    ERR_put_error(8,0x67,0x65,"obj_dat.c",iVar2);
  }
  else {
    iVar2 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar2) {
      num = ASN1_object_size(0,iVar2,6);
      ptr = (uchar *)CRYPTO_malloc(num,"obj_dat.c",0x1c4);
      if (ptr != (uchar *)0x0) {
        local_38 = ptr;
        ASN1_put_object(&local_38,0,iVar2,6,0);
        a2d_ASN1_OBJECT(local_38,iVar2,s,-1);
        local_30[0] = ptr;
        pAVar3 = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,local_30,num);
        CRYPTO_free(ptr);
        return pAVar3;
      }
    }
    pAVar3 = (ASN1_OBJECT *)0x0;
  }
  return pAVar3;
}

