
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  uint uVar1;
  int iVar2;
  int num;
  uchar *ptr;
  ASN1_OBJECT *pAVar3;
  void *pvVar4;
  int in_GS_OFFSET;
  uchar *local_40;
  uchar **local_3c;
  uchar *local_38 [2];
  uint local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  if (no_name == 0) {
    uVar1 = OBJ_sn2nid(s);
    if (uVar1 == 0) {
      uVar1 = OBJ_ln2nid(s);
      if (uVar1 == 0) goto LAB_080d7217;
    }
    if (uVar1 < 0x398) {
      pAVar3 = (ASN1_OBJECT *)(nid_objs + uVar1 * 0x18);
      if (*(int *)(nid_objs + uVar1 * 0x18 + 8) != 0) goto LAB_080d72aa;
      iVar2 = 0x12a;
    }
    else {
      if (added == (_LHASH *)0x0) goto LAB_080d7340;
      local_3c = local_38;
      local_40 = (uchar *)0x3;
      local_30 = uVar1;
      pvVar4 = lh_retrieve(added,&local_40);
      if (pvVar4 != (void *)0x0) {
        pAVar3 = *(ASN1_OBJECT **)((int)pvVar4 + 4);
        goto LAB_080d72aa;
      }
      iVar2 = 0x13b;
    }
    ERR_put_error(8,0x67,0x65,"obj_dat.c",iVar2);
  }
  else {
LAB_080d7217:
    iVar2 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar2) {
      num = ASN1_object_size(0,iVar2,6);
      ptr = (uchar *)CRYPTO_malloc(num,"obj_dat.c",0x1c4);
      if (ptr != (uchar *)0x0) {
        local_40 = ptr;
        ASN1_put_object(&local_40,0,iVar2,6,0);
        a2d_ASN1_OBJECT(local_40,iVar2,s,-1);
        local_38[0] = ptr;
        pAVar3 = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,local_38,num);
        CRYPTO_free(ptr);
        goto LAB_080d72aa;
      }
    }
  }
LAB_080d7340:
  pAVar3 = (ASN1_OBJECT *)0x0;
LAB_080d72aa:
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return pAVar3;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

