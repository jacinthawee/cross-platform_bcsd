
int OBJ_ln2nid(char *s)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined1 *puVar4;
  void *ptr;
  ASN1_OBJECT *o;
  int iVar5;
  char *pcVar6;
  char *in_a2;
  char *pcVar7;
  char *in_a3;
  undefined1 *unaff_s0;
  undefined1 *puVar8;
  void *unaff_s1;
  char *unaff_s2;
  undefined1 *unaff_s3;
  undefined1 *unaff_s5;
  char *pcVar9;
  undefined1 *unaff_s6;
  undefined1 *puVar10;
  undefined1 *unaff_s7;
  void **ppvVar11;
  code *pcVar12;
  int unaff_s8;
  code *pcStack_188;
  void *pvStack_16c;
  void **ppvStack_168;
  void *apvStack_164 [2];
  uint uStack_15c;
  int iStack_14c;
  undefined1 *puStack_148;
  void *pvStack_144;
  undefined *puStack_140;
  char *pcStack_13c;
  char *pcStack_138;
  code *pcStack_134;
  undefined4 uStack_120;
  undefined *puStack_118;
  void *pvStack_10c;
  void **ppvStack_108;
  void *apvStack_104 [2];
  uint uStack_fc;
  char *pcStack_ec;
  undefined1 *puStack_e8;
  void *pvStack_e4;
  char *pcStack_e0;
  undefined1 *puStack_dc;
  undefined *puStack_d8;
  code *pcStack_d4;
  undefined *puStack_c0;
  void *pvStack_b4;
  char **ppcStack_b0;
  char *apcStack_ac [6];
  char *pcStack_94;
  undefined1 *puStack_90;
  void *pvStack_8c;
  char *pcStack_88;
  undefined1 *puStack_84;
  undefined *puStack_80;
  undefined1 *puStack_7c;
  undefined1 *puStack_78;
  undefined1 *puStack_74;
  int iStack_70;
  code *pcStack_6c;
  undefined *local_58;
  undefined4 local_4c;
  undefined *local_48;
  undefined auStack_44 [4];
  char *local_40;
  char *local_2c;
  
  puStack_80 = PTR___stack_chk_guard_006aabf0;
  local_58 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  local_40 = s;
  if (added == 0) {
LAB_004c6570:
    unaff_s2 = local_40;
    unaff_s7 = (undefined1 *)0x391;
    unaff_s6 = (undefined1 *)0x0;
    unaff_s5 = ln_objs;
    unaff_s3 = nid_objs;
    do {
      puVar4 = unaff_s7 + (int)unaff_s6;
      while( true ) {
        unaff_s0 = (undefined1 *)((int)puVar4 >> 1);
        iVar2 = *(int *)(ln_objs + (int)unaff_s0 * 4);
        unaff_s8 = iVar2 * 8;
        unaff_s1 = (void *)(iVar2 * 0x20);
        iVar5 = (**(code **)(local_58 + -0x52c0))
                          (unaff_s2,*(undefined4 *)(nid_objs + iVar2 * 0x18 + 4));
        if (-1 < iVar5) break;
        puVar4 = unaff_s0 + (int)unaff_s6;
        unaff_s7 = unaff_s0;
        if ((int)unaff_s0 <= (int)unaff_s6) goto LAB_004c65ec;
      }
      unaff_s6 = unaff_s0 + 1;
      if (iVar5 == 0) goto LAB_004c65fc;
      puVar4 = unaff_s0;
    } while ((int)unaff_s6 < (int)unaff_s7);
LAB_004c65ec:
    unaff_s0 = puVar4;
    if (iVar5 == 0) {
LAB_004c65fc:
      iVar2 = *(int *)(nid_objs + iVar2 * 0x18 + 8);
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    local_4c = 2;
    local_48 = auStack_44;
    iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(added,&local_4c);
    if (iVar2 == 0) goto LAB_004c6570;
    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8);
  }
  if (local_2c == *(char **)puStack_80) {
    return iVar2;
  }
  pcStack_6c = OBJ_sn2nid;
  apcStack_ac[0] = local_2c;
  (**(code **)(local_58 + -0x5328))();
  pcStack_138 = PTR___stack_chk_guard_006aabf0;
  puStack_c0 = &_gp;
  pcStack_94 = *(char **)PTR___stack_chk_guard_006aabf0;
  puStack_90 = unaff_s0;
  pvStack_8c = unaff_s1;
  pcStack_88 = unaff_s2;
  puStack_84 = unaff_s3;
  puStack_7c = unaff_s5;
  puStack_78 = unaff_s6;
  puStack_74 = unaff_s7;
  iStack_70 = unaff_s8;
  if (added == 0) {
LAB_004c66e4:
    unaff_s2 = apcStack_ac[0];
    puVar4 = (undefined1 *)0x391;
    puVar10 = (undefined1 *)0x0;
    unaff_s3 = nid_objs;
    do {
      puVar8 = puVar4 + (int)puVar10;
      while( true ) {
        puStack_148 = (undefined1 *)((int)puVar8 >> 1);
        iVar2 = *(int *)(sn_objs + (int)puStack_148 * 4);
        unaff_s1 = (void *)(iVar2 * 0x20);
        pcVar6 = *(char **)(nid_objs + iVar2 * 0x18);
        iVar5 = (**(code **)(puStack_c0 + -0x52c0))(unaff_s2);
        if (-1 < iVar5) break;
        puVar8 = puStack_148 + (int)puVar10;
        puVar4 = puStack_148;
        if ((int)puStack_148 <= (int)puVar10) goto LAB_004c6760;
      }
      puVar10 = puStack_148 + 1;
      if (iVar5 == 0) goto LAB_004c6770;
      puVar8 = puStack_148;
    } while ((int)puVar10 < (int)puVar4);
LAB_004c6760:
    puStack_148 = puVar8;
    if (iVar5 == 0) {
LAB_004c6770:
      iVar2 = *(int *)(nid_objs + iVar2 * 0x18 + 8);
    }
    else {
      iVar2 = 0;
    }
  }
  else {
    pcVar6 = (char *)&pvStack_b4;
    pvStack_b4 = (void *)0x1;
    ppcStack_b0 = apcStack_ac;
    iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar2 == 0) goto LAB_004c66e4;
    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8);
    puStack_148 = unaff_s0;
  }
  if (pcStack_94 == *(char **)pcStack_138) {
    return iVar2;
  }
  pcStack_d4 = OBJ_txt2obj;
  pcStack_13c = pcStack_94;
  (**(code **)(puStack_c0 + -0x5328))();
  puStack_140 = PTR___stack_chk_guard_006aabf0;
  puStack_d8 = pcStack_138;
  puStack_118 = &_gp;
  pcStack_ec = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar12 = (code *)PTR_a2d_ASN1_OBJECT_006a95c0;
  puStack_e8 = puStack_148;
  pvStack_e4 = unaff_s1;
  pcStack_e0 = unaff_s2;
  puStack_dc = unaff_s3;
  if ((void **)pcVar6 == (void **)0x0) {
    uVar3 = OBJ_sn2nid(pcStack_13c);
    if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcStack_13c), uVar3 == 0)) {
      pcVar12 = *(code **)(puStack_118 + -0x6920);
      goto LAB_004c67f8;
    }
    if (uVar3 < 0x398) {
      puVar4 = nid_objs + uVar3 * 0x18;
      in_a3 = "Number";
      if (*(int *)(nid_objs + uVar3 * 0x18 + 8) != 0) goto LAB_004c68cc;
      pcVar12 = *(code **)(puStack_118 + -0x6eb0);
      uStack_120 = 0x12a;
LAB_004c6974:
      in_a3 = "obj_dat.c";
      in_a2 = &DAT_00000065;
      pcVar6 = (char *)0x67;
      (*pcVar12)(8);
      goto LAB_004c6988;
    }
    if (added == 0) goto LAB_004c6988;
    pcVar6 = (char *)&pvStack_10c;
    pvStack_10c = (void *)0x3;
    ppvStack_108 = apvStack_104;
    uStack_fc = uVar3;
    iVar2 = (**(code **)(puStack_118 + -0x7a30))();
    if (iVar2 == 0) {
      pcVar12 = *(code **)(puStack_118 + -0x6eb0);
      uStack_120 = 0x13b;
      goto LAB_004c6974;
    }
    puVar4 = *(undefined1 **)(iVar2 + 4);
  }
  else {
LAB_004c67f8:
    in_a3 = (char *)0xffffffff;
    pcVar6 = (char *)0x0;
    in_a2 = pcStack_13c;
    puStack_148 = (undefined1 *)(*pcVar12)(0);
    if (0 < (int)puStack_148) {
      pcStack_138 = (char *)(**(code **)(puStack_118 + -0x69e4))(0,puStack_148,6);
      in_a2 = (char *)0x1c4;
      pcVar6 = "obj_dat.c";
      unaff_s1 = CRYPTO_malloc((int)pcStack_138,"obj_dat.c",0x1c4);
      if (unaff_s1 != (void *)0x0) {
        uStack_120 = 0;
        pvStack_10c = unaff_s1;
        (**(code **)(puStack_118 + -0x69e0))(&pvStack_10c,0,puStack_148,6);
        in_a3 = (char *)0xffffffff;
        (**(code **)(puStack_118 + -0x6920))(pvStack_10c,puStack_148,pcStack_13c);
        pcVar6 = (char *)apvStack_104;
        in_a2 = pcStack_138;
        apvStack_104[0] = unaff_s1;
        puVar4 = (undefined1 *)(**(code **)(puStack_118 + -0x691c))(0);
        CRYPTO_free(unaff_s1);
        puStack_148 = puVar4;
        goto LAB_004c68cc;
      }
    }
LAB_004c6988:
    puVar4 = (undefined1 *)0x0;
  }
LAB_004c68cc:
  if (pcStack_ec == *(char **)puStack_140) {
    return (int)puVar4;
  }
  pcStack_134 = OBJ_txt2nid;
  pcVar9 = pcStack_ec;
  (**(code **)(puStack_118 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_14c = *(int *)PTR___stack_chk_guard_006aabf0;
  pvStack_144 = unaff_s1;
  uVar3 = OBJ_sn2nid(pcVar9);
  if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcVar9), uVar3 == 0)) {
    in_a3 = (char *)0xffffffff;
    pcVar6 = (char *)0x0;
    pcVar7 = pcVar9;
    iVar2 = (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(0);
    if (0 < iVar2) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a94fc)(0,iVar2,6);
      pcVar7 = (char *)0x1c4;
      pcVar6 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1c4);
      if (ptr != (void *)0x0) {
        pcStack_188 = (code *)0x0;
        pvStack_16c = ptr;
        (*(code *)PTR_ASN1_put_object_006a9500)(&pvStack_16c,0,iVar2,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(pvStack_16c,iVar2,pcVar9);
        pcVar6 = (char *)apvStack_164;
        apvStack_164[0] = ptr;
        o = (ASN1_OBJECT *)(*(code *)PTR_d2i_ASN1_OBJECT_006a95c4)(0);
        CRYPTO_free(ptr);
        goto LAB_004c6b24;
      }
    }
  }
  else {
    if (uVar3 < 0x398) {
      o = (ASN1_OBJECT *)(nid_objs + uVar3 * 0x18);
      if (*(int *)(nid_objs + uVar3 * 0x18 + 8) != 0) goto LAB_004c6b24;
      pcStack_188 = (code *)0x12a;
    }
    else {
      pcVar7 = in_a2;
      if (added == 0) goto LAB_004c6bbc;
      pcVar6 = (char *)&pvStack_16c;
      pvStack_16c = (void *)0x3;
      ppvStack_168 = apvStack_164;
      uStack_15c = uVar3;
      iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar2 != 0) {
        o = *(ASN1_OBJECT **)(iVar2 + 4);
        goto LAB_004c6b24;
      }
      pcStack_188 = (code *)0x13b;
    }
    in_a3 = "obj_dat.c";
    pcVar7 = &DAT_00000065;
    pcVar6 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a9030)(8);
  }
LAB_004c6bbc:
  in_a2 = pcVar7;
  o = (ASN1_OBJECT *)0x0;
LAB_004c6b24:
  iVar2 = OBJ_obj2nid(o);
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(o);
  if (iStack_14c == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_14c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0 < (int)in_a2) {
    pcVar9 = (char *)0x0;
    do {
      while( true ) {
        pcVar7 = (char *)((int)(in_a2 + (int)pcVar9) / 2);
        ppvVar11 = (void **)((int)in_a3 * (int)pcVar7 + (int)pcVar6);
        iVar5 = (*pcStack_188)(iVar2,ppvVar11);
        if (-1 < iVar5) break;
        in_a2 = pcVar7;
        if ((int)pcVar7 <= (int)pcVar9) goto LAB_004c6c80;
      }
      pcVar9 = pcVar7 + 1;
      if (iVar5 == 0) {
        return (int)ppvVar11;
      }
    } while ((int)pcVar9 < (int)in_a2);
LAB_004c6c80:
    if (iVar5 == 0) {
      return (int)ppvVar11;
    }
  }
  return 0;
}

