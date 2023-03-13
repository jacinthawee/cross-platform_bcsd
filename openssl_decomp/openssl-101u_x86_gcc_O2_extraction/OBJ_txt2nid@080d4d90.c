
int OBJ_txt2nid(char *s)

{
  uint uVar1;
  int iVar2;
  int iVar3;
  uchar *ptr;
  ASN1_OBJECT *a;
  void *pvVar4;
  int iVar5;
  size_t __n;
  int iVar6;
  int iVar7;
  int in_GS_OFFSET;
  uchar *local_40;
  uchar **local_3c;
  uchar *local_38;
  ASN1_OBJECT *local_34;
  uint local_30;
  int local_20;
  
  local_20 = *(int *)(in_GS_OFFSET + 0x14);
  uVar1 = OBJ_sn2nid(s);
  if ((uVar1 == 0) && (uVar1 = OBJ_ln2nid(s), uVar1 == 0)) {
    iVar2 = a2d_ASN1_OBJECT((uchar *)0x0,0,s,-1);
    if (0 < iVar2) {
      iVar3 = ASN1_object_size(0,iVar2,6);
      ptr = (uchar *)CRYPTO_malloc(iVar3,"obj_dat.c",0x1d6);
      if (ptr != (uchar *)0x0) {
        local_40 = ptr;
        ASN1_put_object(&local_40,0,iVar2,6,0);
        a2d_ASN1_OBJECT(local_40,iVar2,s,-1);
        local_38 = ptr;
        a = d2i_ASN1_OBJECT((ASN1_OBJECT **)0x0,&local_38,iVar3);
        CRYPTO_free(ptr);
        goto joined_r0x080d4ebb;
      }
    }
  }
  else if (uVar1 < 0x398) {
    a = (ASN1_OBJECT *)(nid_objs + uVar1 * 0x18);
    if (*(int *)(nid_objs + uVar1 * 0x18 + 8) != 0) goto joined_r0x080d4ebb;
    iVar2 = 0x140;
LAB_080d4f4d:
    ERR_put_error(8,0x67,0x65,"obj_dat.c",iVar2);
  }
  else if (added != (_LHASH *)0x0) {
    local_3c = &local_38;
    local_40 = (uchar *)0x3;
    local_30 = uVar1;
    pvVar4 = lh_retrieve(added,&local_40);
    if (pvVar4 == (void *)0x0) {
      iVar2 = 0x14e;
      goto LAB_080d4f4d;
    }
    a = *(ASN1_OBJECT **)((int)pvVar4 + 4);
joined_r0x080d4ebb:
    if (a != (ASN1_OBJECT *)0x0) {
      iVar2 = a->nid;
      if (iVar2 != 0) goto LAB_080d4eff;
      __n = a->length;
      if (__n != 0) {
        if (added != (_LHASH *)0x0) {
          local_38 = (uchar *)0x0;
          local_34 = a;
          pvVar4 = lh_retrieve(added,&local_38);
          if (pvVar4 != (void *)0x0) {
            iVar2 = *(int *)(*(int *)((int)pvVar4 + 4) + 8);
            goto LAB_080d4eff;
          }
          __n = a->length;
          iVar2 = 0;
          iVar3 = 0x359;
          if (__n == 0) {
            do {
              iVar7 = iVar2 + iVar3 >> 1;
              iVar6 = *(int *)(obj_objs + iVar7 * 4);
              if (*(int *)(nid_objs + iVar6 * 0x18 + 0xc) == 0) goto LAB_080d5011;
              if (*(int *)(nid_objs + iVar6 * 0x18 + 0xc) < 1) {
                iVar2 = iVar7 + 1;
                iVar7 = iVar3;
              }
              iVar3 = iVar7;
            } while (iVar2 < iVar7);
            goto LAB_080d4e68;
          }
        }
        iVar2 = 0;
        iVar3 = 0x359;
        do {
          iVar7 = iVar3 + iVar2 >> 1;
          iVar6 = *(int *)(obj_objs + iVar7 * 4);
          if (__n == *(size_t *)(nid_objs + iVar6 * 0x18 + 0xc)) {
            iVar5 = memcmp(a->data,*(void **)(nid_objs + iVar6 * 0x18 + 0x10),__n);
            if (-1 < iVar5) {
              if (iVar5 == 0) goto LAB_080d5011;
LAB_080d4fb8:
              iVar2 = iVar7 + 1;
              iVar7 = iVar3;
            }
          }
          else if (-1 < (int)(__n - *(size_t *)(nid_objs + iVar6 * 0x18 + 0xc))) goto LAB_080d4fb8;
          iVar3 = iVar7;
        } while (iVar2 < iVar7);
      }
    }
LAB_080d4e68:
    iVar2 = 0;
    goto LAB_080d4eff;
  }
  a = (ASN1_OBJECT *)0x0;
  iVar2 = 0;
LAB_080d4eff:
  ASN1_OBJECT_free(a);
  if (local_20 != *(int *)(in_GS_OFFSET + 0x14)) {
                    /* WARNING: Subroutine does not return */
    __stack_chk_fail();
  }
  return iVar2;
LAB_080d5011:
  iVar2 = *(int *)(nid_objs + iVar6 * 0x18 + 8);
  goto LAB_080d4eff;
}

