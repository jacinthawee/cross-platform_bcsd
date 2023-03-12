
int OBJ_txt2nid(char *s)

{
  uint uVar1;
  int iVar2;
  int num;
  uchar *ptr;
  ASN1_OBJECT *o;
  void *pvVar3;
  int in_GS_OFFSET;
  uchar *local_40;
  uchar **local_3c;
  uchar *local_38 [2];
  uint local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = OBJ_sn2nid(s);
  if (uVar1 == 0) {
    uVar1 = OBJ_ln2nid(s);
    if (uVar1 != 0) goto LAB_080d7430;
    iVar2 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar2) {
      num = ASN1_object_size(0,iVar2,6);
      ptr = (uchar *)CRYPTO_malloc(num,"obj_dat.c",0x1c4);
      if (ptr != (uchar *)0x0) {
        local_40 = ptr;
        ASN1_put_object(&local_40,0,iVar2,6,0);
        a2d_ASN1_OBJECT(local_40,iVar2,s,-1);
        local_38[0] = ptr;
        o = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,local_38,num);
        CRYPTO_free(ptr);
        goto LAB_080d7471;
      }
    }
  }
  else {
LAB_080d7430:
    if (uVar1 < 0x398) {
      o = (ASN1_OBJECT *)(nid_objs + uVar1 * 0x18);
      if (*(int *)(nid_objs + uVar1 * 0x18 + 8) != 0) goto LAB_080d7471;
      iVar2 = 0x12a;
    }
    else {
      if (added == (_LHASH *)0x0) goto LAB_080d74d0;
      local_3c = local_38;
      local_40 = (uchar *)0x3;
      local_30 = uVar1;
      pvVar3 = lh_retrieve(added,&local_40);
      if (pvVar3 != (void *)0x0) {
        o = *(ASN1_OBJECT **)((int)pvVar3 + 4);
        goto LAB_080d7471;
      }
      iVar2 = 0x13b;
    }
    ERR_put_error(8,0x67,0x65,"obj_dat.c",iVar2);
  }
LAB_080d74d0:
  o = (ASN1_OBJECT *)0x0;
LAB_080d7471:
  iVar2 = OBJ_obj2nid(o);
  ASN1_OBJECT_free(o);
  if (local_20 == *(int *)(in_GS_OFFSET + 0x14)) {
    return iVar2;
  }
                    /* WARNING: Subroutine does not return */
  __stack_chk_fail();
}

