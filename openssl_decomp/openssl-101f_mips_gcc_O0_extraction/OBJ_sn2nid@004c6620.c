
int OBJ_sn2nid(char *s)

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
  char *pcVar9;
  undefined1 *puVar10;
  void **ppvVar11;
  code *pcVar12;
  code *pcStack_120;
  void *pvStack_104;
  void **ppvStack_100;
  void *apvStack_fc [2];
  uint uStack_f4;
  int iStack_e4;
  undefined1 *puStack_e0;
  void *pvStack_dc;
  undefined *puStack_d8;
  char *pcStack_d4;
  char *pcStack_d0;
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
  
  pcStack_d0 = PTR___stack_chk_guard_006aabf0;
  local_58 = &_gp;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  local_44[0] = s;
  if (added == 0) {
LAB_004c66e4:
    unaff_s2 = local_44[0];
    puVar4 = (undefined1 *)0x391;
    puVar10 = (undefined1 *)0x0;
    unaff_s3 = nid_objs;
    do {
      puVar8 = puVar4 + (int)puVar10;
      while( true ) {
        puStack_e0 = (undefined1 *)((int)puVar8 >> 1);
        iVar2 = *(int *)(sn_objs + (int)puStack_e0 * 4);
        unaff_s1 = (void *)(iVar2 * 0x20);
        pcVar6 = *(char **)(nid_objs + iVar2 * 0x18);
        iVar5 = (**(code **)(local_58 + -0x52c0))(unaff_s2);
        if (-1 < iVar5) break;
        puVar8 = puStack_e0 + (int)puVar10;
        puVar4 = puStack_e0;
        if ((int)puStack_e0 <= (int)puVar10) goto LAB_004c6760;
      }
      puVar10 = puStack_e0 + 1;
      if (iVar5 == 0) goto LAB_004c6770;
      puVar8 = puStack_e0;
    } while ((int)puVar10 < (int)puVar4);
LAB_004c6760:
    puStack_e0 = puVar8;
    if (iVar5 == 0) {
LAB_004c6770:
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
    iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)(added);
    if (iVar2 == 0) goto LAB_004c66e4;
    iVar2 = *(int *)(*(int *)(iVar2 + 4) + 8);
    puStack_e0 = unaff_s0;
  }
  if (local_2c == *(char **)pcStack_d0) {
    return iVar2;
  }
  pcStack_6c = OBJ_txt2obj;
  pcStack_d4 = local_2c;
  (**(code **)(local_58 + -0x5328))();
  puStack_d8 = PTR___stack_chk_guard_006aabf0;
  puStack_70 = pcStack_d0;
  puStack_b0 = &_gp;
  pcStack_84 = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar12 = (code *)PTR_a2d_ASN1_OBJECT_006a95c0;
  puStack_80 = puStack_e0;
  pvStack_7c = unaff_s1;
  pcStack_78 = unaff_s2;
  puStack_74 = unaff_s3;
  if ((void **)pcVar6 == (void **)0x0) {
    uVar3 = OBJ_sn2nid(pcStack_d4);
    if ((uVar3 == 0) && (uVar3 = OBJ_ln2nid(pcStack_d4), uVar3 == 0)) {
      pcVar12 = *(code **)(puStack_b0 + -0x6920);
      goto LAB_004c67f8;
    }
    if (uVar3 < 0x398) {
      puVar4 = nid_objs + uVar3 * 0x18;
      in_a3 = "Number";
      if (*(int *)(nid_objs + uVar3 * 0x18 + 8) != 0) goto LAB_004c68cc;
      pcVar12 = *(code **)(puStack_b0 + -0x6eb0);
      uStack_b8 = 0x12a;
LAB_004c6974:
      in_a3 = "obj_dat.c";
      in_a2 = &DAT_00000065;
      pcVar6 = (char *)0x67;
      (*pcVar12)(8);
      goto LAB_004c6988;
    }
    if (added == 0) goto LAB_004c6988;
    pcVar6 = (char *)&pvStack_a4;
    pvStack_a4 = (void *)0x3;
    ppvStack_a0 = apvStack_9c;
    uStack_94 = uVar3;
    iVar2 = (**(code **)(puStack_b0 + -0x7a30))();
    if (iVar2 == 0) {
      pcVar12 = *(code **)(puStack_b0 + -0x6eb0);
      uStack_b8 = 0x13b;
      goto LAB_004c6974;
    }
    puVar4 = *(undefined1 **)(iVar2 + 4);
  }
  else {
LAB_004c67f8:
    in_a3 = (char *)0xffffffff;
    pcVar6 = (char *)0x0;
    in_a2 = pcStack_d4;
    puStack_e0 = (undefined1 *)(*pcVar12)(0);
    if (0 < (int)puStack_e0) {
      pcStack_d0 = (char *)(**(code **)(puStack_b0 + -0x69e4))(0,puStack_e0,6);
      in_a2 = (char *)0x1c4;
      pcVar6 = "obj_dat.c";
      unaff_s1 = CRYPTO_malloc((int)pcStack_d0,"obj_dat.c",0x1c4);
      if (unaff_s1 != (void *)0x0) {
        uStack_b8 = 0;
        pvStack_a4 = unaff_s1;
        (**(code **)(puStack_b0 + -0x69e0))(&pvStack_a4,0,puStack_e0,6);
        in_a3 = (char *)0xffffffff;
        (**(code **)(puStack_b0 + -0x6920))(pvStack_a4,puStack_e0,pcStack_d4);
        pcVar6 = (char *)apvStack_9c;
        in_a2 = pcStack_d0;
        apvStack_9c[0] = unaff_s1;
        puVar4 = (undefined1 *)(**(code **)(puStack_b0 + -0x691c))(0);
        CRYPTO_free(unaff_s1);
        puStack_e0 = puVar4;
        goto LAB_004c68cc;
      }
    }
LAB_004c6988:
    puVar4 = (undefined1 *)0x0;
  }
LAB_004c68cc:
  if (pcStack_84 == *(char **)puStack_d8) {
    return (int)puVar4;
  }
  pcStack_cc = OBJ_txt2nid;
  pcVar9 = pcStack_84;
  (**(code **)(puStack_b0 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_e4 = *(int *)PTR___stack_chk_guard_006aabf0;
  pvStack_dc = unaff_s1;
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
        pcStack_120 = (code *)0x0;
        pvStack_104 = ptr;
        (*(code *)PTR_ASN1_put_object_006a9500)(&pvStack_104,0,iVar2,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(pvStack_104,iVar2,pcVar9);
        pcVar6 = (char *)apvStack_fc;
        apvStack_fc[0] = ptr;
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
      pcStack_120 = (code *)0x12a;
    }
    else {
      pcVar7 = in_a2;
      if (added == 0) goto LAB_004c6bbc;
      pcVar6 = (char *)&pvStack_104;
      pvStack_104 = (void *)0x3;
      ppvStack_100 = apvStack_fc;
      uStack_f4 = uVar3;
      iVar2 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar2 != 0) {
        o = *(ASN1_OBJECT **)(iVar2 + 4);
        goto LAB_004c6b24;
      }
      pcStack_120 = (code *)0x13b;
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
  if (iStack_e4 == *(int *)puVar1) {
    return iVar2;
  }
  iVar2 = iStack_e4;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0 < (int)in_a2) {
    pcVar9 = (char *)0x0;
    do {
      while( true ) {
        pcVar7 = (char *)((int)(in_a2 + (int)pcVar9) / 2);
        ppvVar11 = (void **)((int)in_a3 * (int)pcVar7 + (int)pcVar6);
        iVar5 = (*pcStack_120)(iVar2,ppvVar11);
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

