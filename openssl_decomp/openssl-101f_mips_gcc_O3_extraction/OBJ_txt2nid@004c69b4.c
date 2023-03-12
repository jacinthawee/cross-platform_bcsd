
int OBJ_txt2nid(char *s)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  void *ptr;
  ASN1_OBJECT *o;
  int iVar4;
  char *in_a1;
  char *in_a2;
  char *pcVar5;
  char *in_a3;
  char *pcVar6;
  void **ppvVar7;
  code *local_58;
  void *local_3c;
  void **local_38;
  void *local_34 [2];
  uint local_2c;
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  uVar2 = OBJ_sn2nid(s);
  if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(s), uVar2 == 0)) {
    in_a3 = (char *)0xffffffff;
    in_a1 = (char *)0x0;
    pcVar5 = s;
    iVar3 = (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(0);
    if (0 < iVar3) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a94fc)(0,iVar3,6);
      pcVar5 = (char *)0x1c4;
      in_a1 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1c4);
      if (ptr != (void *)0x0) {
        local_58 = (code *)0x0;
        local_3c = ptr;
        (*(code *)PTR_ASN1_put_object_006a9500)(&local_3c,0,iVar3,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a95c0)(local_3c,iVar3,s);
        in_a1 = (char *)local_34;
        local_34[0] = ptr;
        o = (ASN1_OBJECT *)(*(code *)PTR_d2i_ASN1_OBJECT_006a95c4)(0);
        CRYPTO_free(ptr);
        goto LAB_004c6b24;
      }
    }
  }
  else {
    if (uVar2 < 0x398) {
      o = (ASN1_OBJECT *)(nid_objs + uVar2 * 0x18);
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) != 0) goto LAB_004c6b24;
      local_58 = (code *)0x12a;
    }
    else {
      pcVar5 = in_a2;
      if (added == 0) goto LAB_004c6bbc;
      in_a1 = (char *)&local_3c;
      local_3c = (void *)0x3;
      local_38 = local_34;
      local_2c = uVar2;
      iVar3 = (*(code *)PTR_lh_retrieve_006a84b0)();
      if (iVar3 != 0) {
        o = *(ASN1_OBJECT **)(iVar3 + 4);
        goto LAB_004c6b24;
      }
      local_58 = (code *)0x13b;
    }
    in_a3 = "obj_dat.c";
    pcVar5 = &DAT_00000065;
    in_a1 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a9030)(8);
  }
LAB_004c6bbc:
  in_a2 = pcVar5;
  o = (ASN1_OBJECT *)0x0;
LAB_004c6b24:
  iVar3 = OBJ_obj2nid(o);
  (*(code *)PTR_ASN1_OBJECT_free_006a8104)(o);
  if (local_1c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (0 < (int)in_a2) {
    pcVar5 = (char *)0x0;
    do {
      while( true ) {
        pcVar6 = (char *)((int)(in_a2 + (int)pcVar5) / 2);
        ppvVar7 = (void **)((int)in_a3 * (int)pcVar6 + (int)in_a1);
        iVar4 = (*local_58)(iVar3,ppvVar7);
        if (-1 < iVar4) break;
        in_a2 = pcVar6;
        if ((int)pcVar6 <= (int)pcVar5) goto LAB_004c6c80;
      }
      pcVar5 = pcVar6 + 1;
      if (iVar4 == 0) {
        return (int)ppvVar7;
      }
    } while ((int)pcVar5 < (int)in_a2);
LAB_004c6c80:
    if (iVar4 == 0) {
      return (int)ppvVar7;
    }
  }
  return 0;
}

