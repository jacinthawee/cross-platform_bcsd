
ASN1_OBJECT * OBJ_txt2obj(char *s,int no_name)

{
  undefined *puVar1;
  uint uVar2;
  ASN1_OBJECT *pAVar3;
  int iVar4;
  void *ptr;
  ASN1_OBJECT *pAVar5;
  int iVar6;
  char *pcVar7;
  char *in_a2;
  char *pcVar8;
  char *in_a3;
  ASN1_OBJECT *unaff_s0;
  void *unaff_s1;
  char *unaff_s4;
  char *pcVar9;
  code *pcVar10;
  code *pcStack_b8;
  void *pvStack_9c;
  void **ppvStack_98;
  void *apvStack_94 [2];
  uint uStack_8c;
  int iStack_7c;
  ASN1_OBJECT *pAStack_78;
  void *pvStack_74;
  undefined *puStack_70;
  char *pcStack_6c;
  char *pcStack_68;
  code *pcStack_64;
  undefined4 local_50;
  undefined *local_48;
  void *local_3c;
  void **local_38;
  void *local_34 [2];
  uint local_2c;
  char *local_1c;
  
  puStack_70 = PTR___stack_chk_guard_006aabf0;
  local_48 = &_gp;
  local_1c = *(char **)PTR___stack_chk_guard_006aabf0;
  pcVar10 = (code *)PTR_a2d_ASN1_OBJECT_006a95c0;
  if (no_name == 0) {
    uVar2 = OBJ_sn2nid(s);
    pcVar7 = (char *)no_name;
    if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(s), pcVar7 = (char *)no_name, uVar2 == 0)) {
      pcVar10 = *(code **)(local_48 + -0x6920);
      goto LAB_004c67f8;
    }
    if (uVar2 < 0x398) {
      pAVar3 = (ASN1_OBJECT *)(nid_objs + uVar2 * 0x18);
      in_a3 = "x";
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) != 0) goto LAB_004c68cc;
      pcVar10 = *(code **)(local_48 + -0x6eb0);
      local_50 = 0x12a;
LAB_004c6974:
      in_a3 = "obj_dat.c";
      in_a2 = &DAT_00000065;
      pcVar7 = (char *)0x67;
      (*pcVar10)(8);
      goto LAB_004c6988;
    }
    if (added == 0) goto LAB_004c6988;
    pcVar7 = (char *)&local_3c;
    local_3c = (void *)0x3;
    local_38 = local_34;
    local_2c = uVar2;
    iVar4 = (**(code **)(local_48 + -0x7a30))();
    if (iVar4 == 0) {
      pcVar10 = *(code **)(local_48 + -0x6eb0);
      local_50 = 0x13b;
      goto LAB_004c6974;
    }
    pAVar3 = *(ASN1_OBJECT **)(iVar4 + 4);
  }
  else {
LAB_004c67f8:
    in_a3 = (char *)0xffffffff;
    pcVar7 = (char *)0x0;
    in_a2 = s;
    unaff_s0 = (ASN1_OBJECT *)(*pcVar10)(0);
    if (0 < (int)unaff_s0) {
      unaff_s4 = (char *)(**(code **)(local_48 + -0x69e4))(0,unaff_s0,6);
      in_a2 = (char *)0x1c4;
      pcVar7 = "obj_dat.c";
      unaff_s1 = CRYPTO_malloc((int)unaff_s4,"obj_dat.c",0x1c4);
      if (unaff_s1 != (void *)0x0) {
        local_50 = 0;
        local_3c = unaff_s1;
        (**(code **)(local_48 + -0x69e0))(&local_3c,0,unaff_s0,6);
        in_a3 = (char *)0xffffffff;
        (**(code **)(local_48 + -0x6920))(local_3c,unaff_s0,s);
        pcVar7 = (char *)local_34;
        in_a2 = unaff_s4;
        local_34[0] = unaff_s1;
        pAVar3 = (ASN1_OBJECT *)(**(code **)(local_48 + -0x691c))(0);
        CRYPTO_free(unaff_s1);
        unaff_s0 = pAVar3;
        goto LAB_004c68cc;
      }
    }
LAB_004c6988:
    pAVar3 = (ASN1_OBJECT *)0x0;
  }
LAB_004c68cc:
  if (local_1c == *(char **)puStack_70) {
    return pAVar3;
  }
  pcStack_64 = OBJ_txt2nid;
  pcVar9 = local_1c;
  (**(code **)(local_48 + -0x5328))();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_7c = *(int *)PTR___stack_chk_guard_006aabf0;
  pAStack_78 = unaff_s0;
  pvStack_74 = unaff_s1;
  pcStack_6c = s;
  pcStack_68 = unaff_s4;
  uVar2 = OBJ_sn2nid(pcVar9);
  if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(pcVar9), uVar2 == 0)) {
    in_a3 = (char *)0xffffffff;
    pcVar7 = (char *)0x0;
    pcVar8 = pcVar9;
    iVar4 = (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(0);
    if (0 < iVar4) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a94fc)(0,iVar4,6);
      pcVar8 = (char *)0x1c4;
      pcVar7 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1c4);
      if (ptr != (void *)0x0) {
        pcStack_b8 = (code *)0x0;
        pvStack_9c = ptr;
        (*(code *)PTR_ASN1_put_object_006a9500)(&pvStack_9c,0,iVar4,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(pvStack_9c,iVar4,pcVar9);
        pcVar7 = (char *)apvStack_94;
        apvStack_94[0] = ptr;
        pAVar3 = (ASN1_OBJECT *)(*(code *)PTR_d2i_ASN1_OBJECT_006a95c4)(0);
        CRYPTO_free(ptr);
        goto LAB_004c6b24;
      }
    }
  }
  else {
    if (uVar2 < 0x398) {
      pAVar3 = (ASN1_OBJECT *)(nid_objs + uVar2 * 0x18);
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) != 0) goto LAB_004c6b24;
      pcStack_b8 = (code *)0x12a;
    }
    else {
      pcVar8 = in_a2;
      if (added == 0) goto LAB_004c6bbc;
      pcVar7 = (char *)&pvStack_9c;
      pvStack_9c = (void *)0x3;
      ppvStack_98 = apvStack_94;
      uStack_8c = uVar2;
      iVar4 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar4 != 0) {
        pAVar3 = *(ASN1_OBJECT **)(iVar4 + 4);
        goto LAB_004c6b24;
      }
      pcStack_b8 = (code *)0x13b;
    }
    in_a3 = "obj_dat.c";
    pcVar8 = &DAT_00000065;
    pcVar7 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a9030)(8);
  }
LAB_004c6bbc:
  in_a2 = pcVar8;
  pAVar3 = (ASN1_OBJECT *)0x0;
LAB_004c6b24:
  pAVar5 = (ASN1_OBJECT *)OBJ_obj2nid(pAVar3);
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(pAVar3);
  if (iStack_7c == *(int *)puVar1) {
    return pAVar5;
  }
  iVar4 = iStack_7c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0 < (int)in_a2) {
    pcVar9 = (char *)0x0;
    do {
      while( true ) {
        pcVar8 = (char *)((int)(in_a2 + (int)pcVar9) / 2);
        pAVar3 = (ASN1_OBJECT *)((int)in_a3 * (int)pcVar8 + (int)pcVar7);
        iVar6 = (*pcStack_b8)(iVar4,pAVar3);
        if (-1 < iVar6) break;
        in_a2 = pcVar8;
        if ((int)pcVar8 <= (int)pcVar9) goto LAB_004c6c80;
      }
      pcVar9 = pcVar8 + 1;
      if (iVar6 == 0) {
        return pAVar3;
      }
    } while ((int)pcVar9 < (int)in_a2);
LAB_004c6c80:
    if (iVar6 == 0) {
      return pAVar3;
    }
  }
  return (ASN1_OBJECT *)0x0;
}

