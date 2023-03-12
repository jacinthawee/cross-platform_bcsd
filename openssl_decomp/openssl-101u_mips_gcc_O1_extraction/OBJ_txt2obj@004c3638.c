
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  void *ptr;
  undefined1 *puVar5;
  int iVar6;
  char *pcVar7;
  char *in_a2;
  char *pcVar8;
  char *in_a3;
  ASN1_OBJECT *unaff_s0;
  char *pcVar9;
  void *unaff_s1;
  char *unaff_s4;
  char *pcVar10;
  char *pcVar11;
  code *pcStack_c8;
  void *pvStack_ac;
  void **ppvStack_a8;
  void *pvStack_a4;
  undefined1 *puStack_a0;
  uint uStack_9c;
  int iStack_8c;
  ASN1_OBJECT *pAStack_88;
  void *pvStack_84;
  undefined *puStack_80;
  char *pcStack_7c;
  char *pcStack_78;
  void *local_3c;
  void **local_38;
  void *local_34 [2];
  uint local_2c;
  char *local_1c;
  
  puStack_80 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(char **)PTR___stack_chk_guard_006a9ae8;
  if ((no_name == 0) &&
     ((uVar2 = OBJ_sn2nid(s), pcVar7 = (char *)no_name, uVar2 != 0 ||
      (uVar2 = OBJ_ln2nid(s), pcVar7 = (char *)no_name, uVar2 != 0)))) {
    if (uVar2 < 0x398) {
      pAVar3 = (ASN1_OBJECT *)(nid_objs + uVar2 * 0x18);
      in_a3 = "TBEX";
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) == 0) {
LAB_004c3818:
        in_a3 = "obj_dat.c";
        in_a2 = &DAT_00000065;
        pcVar7 = (char *)0x67;
        (*(code *)PTR_ERR_put_error_006a7f34)(8);
        goto LAB_004c382c;
      }
    }
    else {
      if (added == 0) goto LAB_004c382c;
      pcVar7 = (char *)&local_3c;
      local_3c = (void *)0x3;
      local_38 = local_34;
      local_2c = uVar2;
      iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)();
      if (iVar4 == 0) goto LAB_004c3818;
      pAVar3 = *(ASN1_OBJECT **)(iVar4 + 4);
    }
  }
  else {
    in_a3 = (char *)0xffffffff;
    pcVar7 = (char *)0x0;
    in_a2 = s;
    unaff_s0 = (ASN1_OBJECT *)(*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(0);
    if (0 < (int)unaff_s0) {
      unaff_s4 = (char *)(*(code *)PTR_ASN1_object_size_006a83e4)(0,unaff_s0,6);
      in_a2 = (char *)0x1d6;
      pcVar7 = "obj_dat.c";
      unaff_s1 = CRYPTO_malloc((int)unaff_s4,"obj_dat.c",0x1d6);
      if (unaff_s1 != (void *)0x0) {
        local_3c = unaff_s1;
        (*(code *)PTR_ASN1_put_object_006a83e8)(&local_3c,0,unaff_s0,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(local_3c,unaff_s0,s);
        pcVar7 = (char *)local_34;
        in_a2 = unaff_s4;
        local_34[0] = unaff_s1;
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_d2i_ASN1_OBJECT_006a84a4)(0);
        CRYPTO_free(unaff_s1);
        unaff_s0 = pAVar3;
        goto LAB_004c3770;
      }
    }
LAB_004c382c:
    pAVar3 = (ASN1_OBJECT *)0x0;
  }
LAB_004c3770:
  if (local_1c == *(char **)puStack_80) {
    return pAVar3;
  }
  pcVar10 = local_1c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_8c = *(int *)PTR___stack_chk_guard_006a9ae8;
  pAStack_88 = unaff_s0;
  pvStack_84 = unaff_s1;
  pcStack_7c = s;
  pcStack_78 = unaff_s4;
  uVar2 = OBJ_sn2nid(pcVar10);
  if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(pcVar10), uVar2 == 0)) {
    in_a3 = (char *)0xffffffff;
    pcVar7 = (char *)0x0;
    pcVar8 = pcVar10;
    iVar4 = (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(0);
    if (0 < iVar4) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a83e4)(0,iVar4,6);
      pcVar8 = (char *)0x1d6;
      pcVar7 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1d6);
      if (ptr != (void *)0x0) {
        pcStack_c8 = (code *)0x0;
        pvStack_ac = ptr;
        (*(code *)PTR_ASN1_put_object_006a83e8)(&pvStack_ac,0,iVar4,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(pvStack_ac,iVar4,pcVar10);
        pcVar7 = (char *)&pvStack_a4;
        pvStack_a4 = ptr;
        puVar5 = (undefined1 *)(*(code *)PTR_d2i_ASN1_OBJECT_006a84a4)(0);
        CRYPTO_free(ptr);
LAB_004c3994:
        pAVar3 = (ASN1_OBJECT *)0x0;
        pcVar8 = in_a2;
        if (puVar5 == (undefined1 *)0x0) goto LAB_004c39e4;
LAB_004c399c:
        pAVar3 = *(ASN1_OBJECT **)(puVar5 + 8);
        pcVar8 = in_a2;
        if (pAVar3 != (ASN1_OBJECT *)0x0) goto LAB_004c39e4;
        pcVar10 = *(char **)(puVar5 + 0xc);
        if (pcVar10 != (char *)0x0) {
          if (added != 0) {
            pcVar7 = (char *)&pvStack_a4;
            pvStack_a4 = (void *)0x0;
            puStack_a0 = puVar5;
            iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)();
            if (iVar4 != 0) {
              pAVar3 = *(ASN1_OBJECT **)(*(int *)(iVar4 + 4) + 8);
              pcVar8 = in_a2;
              goto LAB_004c39e4;
            }
            pcVar10 = *(char **)(puVar5 + 0xc);
            if (pcVar10 == (char *)0x0) {
              pcVar7 = (char *)0x0;
              in_a2 = (char *)0x359;
              do {
                pcVar8 = (char *)((int)((int)pcVar7 + (int)in_a2) >> 1);
                iVar4 = *(int *)(obj_objs + (int)pcVar8 * 4);
                if (*(int *)(nid_objs + iVar4 * 0x18 + 0xc) == 0) goto LAB_004c3c0c;
                if (*(int *)(nid_objs + iVar4 * 0x18 + 0xc) < 1) {
                  pcVar7 = pcVar8 + 1;
                  pcVar8 = in_a2;
                }
                pAVar3 = (ASN1_OBJECT *)0x0;
                in_a2 = pcVar8;
              } while ((int)pcVar7 < (int)pcVar8);
              goto LAB_004c39e4;
            }
          }
          pcVar11 = (char *)0x0;
          pcVar7 = nid_objs + obj_objs._1712_4_ * 0x18;
          iVar6 = (int)pcVar10 - *(int *)(nid_objs + obj_objs._1712_4_ * 0x18 + 0xc);
          in_a3 = (char *)0x359;
          pcVar9 = (char *)0x1ac;
          iVar4 = obj_objs._1712_4_;
          if (iVar6 != 0) goto LAB_004c3b98;
LAB_004c3b30:
          pcVar7 = *(char **)((int)pcVar7 + 0x10);
          in_a2 = pcVar10;
          iVar6 = (*(code *)PTR_memcmp_006a9ad0)(*(undefined4 *)(puVar5 + 0x10));
          if (iVar6 < 0) goto LAB_004c3b58;
          if (iVar6 != 0) {
            do {
              pcVar11 = pcVar9 + 1;
              pcVar9 = in_a3;
LAB_004c3b58:
              do {
                pAVar3 = (ASN1_OBJECT *)0x0;
                pcVar8 = in_a2;
                in_a3 = pcVar9;
                if ((int)pcVar9 <= (int)pcVar11) goto LAB_004c39e4;
                pcVar9 = (char *)((int)(pcVar9 + (int)pcVar11) >> 1);
                iVar4 = *(int *)(obj_objs + (int)pcVar9 * 4);
                pcVar7 = nid_objs + iVar4 * 0x18;
                iVar6 = (int)pcVar10 - *(int *)(nid_objs + iVar4 * 0x18 + 0xc);
                if (iVar6 == 0) goto LAB_004c3b30;
LAB_004c3b98:
              } while (iVar6 < 0);
            } while( true );
          }
LAB_004c3c0c:
          pAVar3 = *(ASN1_OBJECT **)(nid_objs + iVar4 * 0x18 + 8);
          pcVar8 = in_a2;
          goto LAB_004c39e4;
        }
LAB_004c3a78:
        pAVar3 = (ASN1_OBJECT *)0x0;
        pcVar8 = in_a2;
        goto LAB_004c39e4;
      }
    }
  }
  else {
    if (uVar2 < 0x398) {
      puVar5 = nid_objs + uVar2 * 0x18;
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) != 0) goto LAB_004c3994;
      pcStack_c8 = (code *)0x140;
    }
    else {
      pcVar8 = in_a2;
      if (added == 0) goto LAB_004c3acc;
      pcVar7 = (char *)&pvStack_ac;
      pvStack_ac = (void *)0x3;
      ppvStack_a8 = &pvStack_a4;
      uStack_9c = uVar2;
      iVar4 = (*(code *)PTR_lh_retrieve_006a73b0)();
      if (iVar4 != 0) {
        puVar5 = *(undefined1 **)(iVar4 + 4);
        if (puVar5 != (undefined1 *)0x0) goto LAB_004c399c;
        goto LAB_004c3a78;
      }
      pcStack_c8 = (code *)0x14e;
    }
    in_a3 = "obj_dat.c";
    pcVar8 = &DAT_00000065;
    pcVar7 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a7f34)(8);
  }
LAB_004c3acc:
  puVar5 = (undefined1 *)0x0;
  pAVar3 = (ASN1_OBJECT *)0x0;
LAB_004c39e4:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar5);
  if (iStack_8c == *(int *)puVar1) {
    return pAVar3;
  }
  iVar4 = iStack_8c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0 < (int)pcVar8) {
    pcVar10 = (char *)0x0;
    do {
      while( true ) {
        pcVar9 = (char *)((int)(pcVar8 + (int)pcVar10) / 2);
        pAVar3 = (ASN1_OBJECT *)((int)in_a3 * (int)pcVar9 + (int)pcVar7);
        iVar6 = (*pcStack_c8)(iVar4,pAVar3);
        if (-1 < iVar6) break;
        pcVar8 = pcVar9;
        if ((int)pcVar9 <= (int)pcVar10) goto LAB_004c3ce0;
      }
      pcVar10 = pcVar9 + 1;
      if (iVar6 == 0) {
        return pAVar3;
      }
    } while ((int)pcVar10 < (int)pcVar8);
LAB_004c3ce0:
    if (iVar6 == 0) {
      return pAVar3;
    }
  }
  return (ASN1_OBJECT *)0x0;
}

