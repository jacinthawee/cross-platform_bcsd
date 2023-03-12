
int OBJ_sn2nid(char *s)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  void *ptr;
  int iVar5;
  char *pcVar6;
  char *in_a2;
  char *pcVar7;
  char *in_a3;
  undefined1 *unaff_s0;
  char *pcVar8;
  void *unaff_s1;
  char *unaff_s2;
  undefined1 *unaff_s3;
  undefined1 *unaff_s5;
  undefined1 *unaff_s6;
  char *pcVar9;
  undefined1 *unaff_s7;
  void **ppvVar10;
  code *pcVar11;
  int unaff_s8;
  char *pcVar12;
  code *pcStack_130;
  void *pvStack_114;
  void **ppvStack_110;
  void *pvStack_10c;
  undefined1 *puStack_108;
  uint uStack_104;
  int iStack_f4;
  undefined1 *puStack_f0;
  void *pvStack_ec;
  undefined *puStack_e8;
  char *pcStack_e4;
  char *pcStack_e0;
  undefined1 *puStack_dc;
  undefined1 *puStack_d8;
  undefined1 *puStack_d4;
  int iStack_d0;
  code *pcStack_cc;
  undefined4 uStack_b8;
  undefined *puStack_b0;
  void *pvStack_a4;
  void **ppvStack_a0;
  void *apvStack_9c [2];
  uint uStack_94;
  char *pcStack_84;
  undefined1 *puStack_80;
  void *pvStack_7c;
  char *pcStack_78;
  undefined1 *puStack_74;
  undefined *puStack_70;
  code *pcStack_6c;
  undefined *local_58;
  void *local_4c;
  char **local_48;
  char *local_44 [6];
  char *local_2c;
  
  pcStack_e0 = PTR___stack_chk_guard_006a9ae8;
  local_58 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006a9ae8;
  local_44[0] = s;
  if (added == 0) {
LAB_004c3588:
    unaff_s2 = local_44[0];
    unaff_s7 = (undefined1 *)0x391;
    unaff_s6 = (undefined1 *)0x0;
    unaff_s5 = sn_objs;
    unaff_s3 = nid_objs;
    do {
      puVar4 = unaff_s7 + (int)unaff_s6;
      while( true ) {
        puStack_f0 = (undefined1 *)((int)puVar4 >> 1);
        iVar2 = *(int *)(sn_objs + (int)puStack_f0 * 4);
        unaff_s8 = iVar2 * 8;
        unaff_s1 = (void *)(iVar2 * 0x20);
        pcVar6 = *(char **)(nid_objs + iVar2 * 0x18);
        iVar5 = (**(code **)(local_58 + -0x52c8))(unaff_s2);
        if (-1 < iVar5) break;
        puVar4 = puStack_f0 + (int)unaff_s6;
        unaff_s7 = puStack_f0;
        if ((int)puStack_f0 <= (int)unaff_s6) goto LAB_004c3604;
      }
      unaff_s6 = puStack_f0 + 1;
      if (iVar5 == 0) goto LAB_004c3614;
      puVar4 = puStack_f0;
    } while ((int)unaff_s6 < (int)unaff_s7);
LAB_004c3604:
    puStack_f0 = puVar4;
    if (iVar5 == 0) {
LAB_004c3614:
      iVar2 = *(int *)(nid_objs + iVar2 * 0x18 + 8);
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    pcVar6 = (char *)&local_4c;
    local_4c = (void *)0x1;
    local_48 = local_44;
    iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)(added);
    if (iVar2 == 0) goto LAB_004c3588;
    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8);
    puStack_f0 = unaff_s0;
  }
  if (local_2c == *(char **)pcStack_e0) {
    return iVar2;
  }
  pcStack_6c = OBJ_txt2obj;
  pcStack_e4 = local_2c;
  (**(code **)(local_58 + -0x5330))();
  puStack_e8 = PTR___stack_chk_guard_006a9ae8;
  puStack_70 = pcStack_e0;
  puStack_b0 = &_gp;
  pcStack_84 = *(char **)PTR___stack_chk_guard_006a9ae8;
  pcVar11 = (code *)PTR_a2d_ASN1_OBJECT_006a84a0;
  puStack_80 = puStack_f0;
  pvStack_7c = unaff_s1;
  pcStack_78 = unaff_s2;
  puStack_74 = unaff_s3;
  if ((void **)pcVar6 == (void **)0x0) {
    uVar3 = OBJ_sn2nid(pcStack_e4);
    if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcStack_e4), uVar3 == 0)) {
      pcVar11 = *(code **)(puStack_b0 + -0x6940);
      goto LAB_004c369c;
    }
    if (uVar3 < 0x398) {
      puVar4 = nid_objs + uVar3 * 0x18;
      in_a3 = "TBEX";
      if (*(int *)(nid_objs + uVar3 * 0x18 + 8) != 0) goto LAB_004c3770;
      pcVar11 = *(code **)(puStack_b0 + -0x6eac);
      uStack_b8 = 0x140;
LAB_004c3818:
      in_a3 = "obj_dat.c";
      in_a2 = &DAT_00000065;
      pcVar6 = (char *)0x67;
      (*pcVar11)(8);
      goto LAB_004c382c;
    }
    if (added == 0) goto LAB_004c382c;
    pcVar6 = (char *)&pvStack_a4;
    pvStack_a4 = (void *)0x3;
    ppvStack_a0 = apvStack_9c;
    uStack_94 = uVar3;
    iVar2 = (**(code **)(puStack_b0 + -0x7a30))();
    if (iVar2 == 0) {
      pcVar11 = *(code **)(puStack_b0 + -0x6eac);
      uStack_b8 = 0x14e;
      goto LAB_004c3818;
    }
    puVar4 = *(undefined1 **)(iVar2 + 4);
  }
  else {
LAB_004c369c:
    in_a3 = (char *)0xffffffff;
    pcVar6 = (char *)0x0;
    in_a2 = pcStack_e4;
    puStack_f0 = (undefined1 *)(*pcVar11)(0);
    if (0 < (int)puStack_f0) {
      pcStack_e0 = (char *)(**(code **)(puStack_b0 + -0x69fc))(0,puStack_f0,6);
      in_a2 = (char *)0x1d6;
      pcVar6 = "obj_dat.c";
      unaff_s1 = CRYPTO_malloc((int)pcStack_e0,"obj_dat.c",0x1d6);
      if (unaff_s1 != (void *)0x0) {
        uStack_b8 = 0;
        pvStack_a4 = unaff_s1;
        (**(code **)(puStack_b0 + -0x69f8))(&pvStack_a4,0,puStack_f0,6);
        in_a3 = (char *)0xffffffff;
        (**(code **)(puStack_b0 + -0x6940))(pvStack_a4,puStack_f0,pcStack_e4);
        pcVar6 = (char *)apvStack_9c;
        in_a2 = pcStack_e0;
        apvStack_9c[0] = unaff_s1;
        puVar4 = (undefined1 *)(**(code **)(puStack_b0 + -0x693c))(0);
        CRYPTO_free(unaff_s1);
        puStack_f0 = puVar4;
        goto LAB_004c3770;
      }
    }
LAB_004c382c:
    puVar4 = (undefined1 *)0x0;
  }
LAB_004c3770:
  if (pcStack_84 == *(char **)puStack_e8) {
    return (int)puVar4;
  }
  pcStack_cc = OBJ_txt2nid;
  pcVar9 = pcStack_84;
  (**(code **)(puStack_b0 + -0x5330))();
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  iStack_f4 = *(int *)PTR___stack_chk_guard_006a9ae8;
  pvStack_ec = unaff_s1;
  puStack_dc = unaff_s5;
  puStack_d8 = unaff_s6;
  puStack_d4 = unaff_s7;
  iStack_d0 = unaff_s8;
  uVar3 = OBJ_sn2nid(pcVar9);
  if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcVar9), uVar3 == 0)) {
    in_a3 = (char *)0xffffffff;
    pcVar6 = (char *)0x0;
    pcVar7 = pcVar9;
    iVar2 = (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(0);
    if (0 < iVar2) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a83e4)(0,iVar2,6);
      pcVar7 = (char *)0x1d6;
      pcVar6 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1d6);
      if (ptr != (void *)0x0) {
        pcStack_130 = (code *)0x0;
        pvStack_114 = ptr;
        (*(code *)PTR_ASN1_put_object_006a83e8)(&pvStack_114,0,iVar2,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(pvStack_114,iVar2,pcVar9);
        pcVar6 = (char *)&pvStack_10c;
        pvStack_10c = ptr;
        puVar4 = (undefined1 *)(*(code *)PTR_d2i_ASN1_OBJECT_006a84a4)(0);
        CRYPTO_free(ptr);
LAB_004c3994:
        iVar2 = 0;
        pcVar7 = in_a2;
        if (puVar4 == (undefined1 *)0x0) goto LAB_004c39e4;
LAB_004c399c:
        iVar2 = *(int *)(puVar4 + 8);
        pcVar7 = in_a2;
        if (iVar2 != 0) goto LAB_004c39e4;
        pcVar9 = *(char **)(puVar4 + 0xc);
        if (pcVar9 != (char *)0x0) {
          if (added != 0) {
            pcVar6 = (char *)&pvStack_10c;
            pvStack_10c = (void *)0x0;
            puStack_108 = puVar4;
            iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)();
            if (iVar2 != 0) {
              iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8);
              pcVar7 = in_a2;
              goto LAB_004c39e4;
            }
            pcVar9 = *(char **)(puVar4 + 0xc);
            if (pcVar9 == (char *)0x0) {
              pcVar6 = (char *)0x0;
              in_a2 = (char *)0x359;
              do {
                pcVar7 = (char *)((int)((int)pcVar6 + (int)in_a2) >> 1);
                iVar2 = *(int *)(obj_objs + (int)pcVar7 * 4);
                if (*(int *)(nid_objs + iVar2 * 0x18 + 0xc) == 0) goto LAB_004c3c0c;
                if (*(int *)(nid_objs + iVar2 * 0x18 + 0xc) < 1) {
                  pcVar6 = pcVar7 + 1;
                  pcVar7 = in_a2;
                }
                iVar2 = 0;
                in_a2 = pcVar7;
              } while ((int)pcVar6 < (int)pcVar7);
              goto LAB_004c39e4;
            }
          }
          pcVar12 = (char *)0x0;
          pcVar6 = nid_objs + obj_objs._1712_4_ * 0x18;
          iVar5 = (int)pcVar9 - *(int *)(nid_objs + obj_objs._1712_4_ * 0x18 + 0xc);
          in_a3 = (char *)0x359;
          pcVar8 = (char *)0x1ac;
          iVar2 = obj_objs._1712_4_;
          if (iVar5 != 0) goto LAB_004c3b98;
LAB_004c3b30:
          pcVar6 = *(char **)((int)pcVar6 + 0x10);
          in_a2 = pcVar9;
          iVar5 = (*(code *)PTR_memcmp_006a9ad0)(*(undefined4 *)(puVar4 + 0x10));
          if (iVar5 < 0) goto LAB_004c3b58;
          if (iVar5 != 0) {
            do {
              pcVar12 = pcVar8 + 1;
              pcVar8 = in_a3;
LAB_004c3b58:
              do {
                iVar2 = 0;
                pcVar7 = in_a2;
                in_a3 = pcVar8;
                if ((int)pcVar8 <= (int)pcVar12) goto LAB_004c39e4;
                pcVar8 = (char *)((int)(pcVar8 + (int)pcVar12) >> 1);
                iVar2 = *(int *)(obj_objs + (int)pcVar8 * 4);
                pcVar6 = nid_objs + iVar2 * 0x18;
                iVar5 = (int)pcVar9 - *(int *)(nid_objs + iVar2 * 0x18 + 0xc);
                if (iVar5 == 0) goto LAB_004c3b30;
LAB_004c3b98:
              } while (iVar5 < 0);
            } while( true );
          }
LAB_004c3c0c:
          iVar2 = *(int *)(nid_objs + iVar2 * 0x18 + 8);
          pcVar7 = in_a2;
          goto LAB_004c39e4;
        }
LAB_004c3a78:
        iVar2 = 0;
        pcVar7 = in_a2;
        goto LAB_004c39e4;
      }
    }
  }
  else {
    if (uVar3 < 0x398) {
      puVar4 = nid_objs + uVar3 * 0x18;
      if (*(int *)(nid_objs + uVar3 * 0x18 + 8) != 0) goto LAB_004c3994;
      pcStack_130 = (code *)0x140;
    }
    else {
      pcVar7 = in_a2;
      if (added == 0) goto LAB_004c3acc;
      pcVar6 = (char *)&pvStack_114;
      pvStack_114 = (void *)0x3;
      ppvStack_110 = &pvStack_10c;
      uStack_104 = uVar3;
      iVar2 = (*(code *)PTR_lh_retrieve_006a73b0)();
      if (iVar2 != 0) {
        puVar4 = *(undefined1 **)(iVar2 + 4);
        if (puVar4 != (undefined1 *)0x0) goto LAB_004c399c;
        goto LAB_004c3a78;
      }
      pcStack_130 = (code *)0x14e;
    }
    in_a3 = "obj_dat.c";
    pcVar7 = &DAT_00000065;
    pcVar6 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a7f34)(8);
  }
LAB_004c3acc:
  puVar4 = (undefined1 *)0x0;
  iVar2 = 0;
LAB_004c39e4:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar4);
  if (iStack_f4 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_f4;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0 < (int)pcVar7) {
    pcVar9 = (char *)0x0;
    do {
      while( true ) {
        pcVar8 = (char *)((int)(pcVar7 + (int)pcVar9) / 2);
        ppvVar10 = (void **)((int)in_a3 * (int)pcVar8 + (int)pcVar6);
        iVar5 = (*pcStack_130)(iVar2,ppvVar10);
        if (-1 < iVar5) break;
        pcVar7 = pcVar8;
        if ((int)pcVar8 <= (int)pcVar9) goto LAB_004c3ce0;
      }
      pcVar9 = pcVar8 + 1;
      if (iVar5 == 0) {
        return (int)ppvVar10;
      }
    } while ((int)pcVar9 < (int)pcVar7);
LAB_004c3ce0:
    if (iVar5 == 0) {
      return (int)ppvVar10;
    }
  }
  return 0;
}

