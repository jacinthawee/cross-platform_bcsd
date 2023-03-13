
int OBJ_txt2nid(char *s)

{
  undefined *puVar1;
  uint uVar2;
  int iVar3;
  void *ptr;
  undefined1 *puVar4;
  int iVar5;
  char *in_a1;
  char *in_a2;
  char *pcVar6;
  char *in_a3;
  char *pcVar7;
  char *pcVar8;
  void **ppvVar9;
  char *pcVar10;
  code *local_68;
  void *local_4c;
  void **local_48;
  void *local_44;
  undefined1 *local_40;
  uint local_3c;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  uVar2 = OBJ_sn2nid(s);
  if ((uVar2 == 0) && (uVar2 = OBJ_ln2nid(s), uVar2 == 0)) {
    in_a3 = (char *)0xffffffff;
    in_a1 = (char *)0x0;
    pcVar6 = s;
    iVar3 = (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(0);
    if (0 < iVar3) {
      in_a2 = (char *)(*(code *)PTR_ASN1_object_size_006a83e4)(0,iVar3,6);
      pcVar6 = (char *)0x1d6;
      in_a1 = "obj_dat.c";
      ptr = CRYPTO_malloc((int)in_a2,"obj_dat.c",0x1d6);
      if (ptr != (void *)0x0) {
        local_68 = (code *)0x0;
        local_4c = ptr;
        (*(code *)PTR_ASN1_put_object_006a83e8)(&local_4c,0,iVar3,6);
        in_a3 = (char *)0xffffffff;
        (*(code *)PTR_a2d_ASN1_OBJECT_006a84a0)(local_4c,iVar3,s);
        in_a1 = (char *)&local_44;
        local_44 = ptr;
        puVar4 = (undefined1 *)(*(code *)PTR_d2i_ASN1_OBJECT_006a84a4)(0);
        CRYPTO_free(ptr);
LAB_004c3994:
        iVar3 = 0;
        pcVar6 = in_a2;
        if (puVar4 == (undefined1 *)0x0) goto LAB_004c39e4;
LAB_004c399c:
        iVar3 = *(int *)(puVar4 + 8);
        pcVar6 = in_a2;
        if (iVar3 != 0) goto LAB_004c39e4;
        pcVar8 = *(char **)(puVar4 + 0xc);
        if (pcVar8 != (char *)0x0) {
          if (added != 0) {
            in_a1 = (char *)&local_44;
            local_44 = (void *)0x0;
            local_40 = puVar4;
            iVar3 = (*(code *)PTR_lh_retrieve_006a73b0)();
            if (iVar3 != 0) {
              iVar3 = *(int *)(*(int *)(iVar3 + 4) + 8);
              pcVar6 = in_a2;
              goto LAB_004c39e4;
            }
            pcVar8 = *(char **)(puVar4 + 0xc);
            if (pcVar8 == (char *)0x0) {
              in_a1 = (char *)0x0;
              in_a2 = (char *)0x359;
              do {
                pcVar6 = (char *)((int)((int)in_a1 + (int)in_a2) >> 1);
                iVar3 = *(int *)(obj_objs + (int)pcVar6 * 4);
                if (*(int *)(nid_objs + iVar3 * 0x18 + 0xc) == 0) goto LAB_004c3c0c;
                if (*(int *)(nid_objs + iVar3 * 0x18 + 0xc) < 1) {
                  in_a1 = pcVar6 + 1;
                  pcVar6 = in_a2;
                }
                iVar3 = 0;
                in_a2 = pcVar6;
              } while ((int)in_a1 < (int)pcVar6);
              goto LAB_004c39e4;
            }
          }
          pcVar10 = (char *)0x0;
          in_a1 = nid_objs + obj_objs._1712_4_ * 0x18;
          iVar5 = (int)pcVar8 - *(int *)(nid_objs + obj_objs._1712_4_ * 0x18 + 0xc);
          in_a3 = (char *)0x359;
          pcVar7 = (char *)0x1ac;
          iVar3 = obj_objs._1712_4_;
          if (iVar5 != 0) goto LAB_004c3b98;
LAB_004c3b30:
          in_a1 = *(char **)((int)in_a1 + 0x10);
          in_a2 = pcVar8;
          iVar5 = (*(code *)PTR_memcmp_006a9ad0)(*(undefined4 *)(puVar4 + 0x10));
          if (iVar5 < 0) goto LAB_004c3b58;
          if (iVar5 != 0) {
            do {
              pcVar10 = pcVar7 + 1;
              pcVar7 = in_a3;
LAB_004c3b58:
              do {
                iVar3 = 0;
                pcVar6 = in_a2;
                in_a3 = pcVar7;
                if ((int)pcVar7 <= (int)pcVar10) goto LAB_004c39e4;
                pcVar7 = (char *)((int)(pcVar7 + (int)pcVar10) >> 1);
                iVar3 = *(int *)(obj_objs + (int)pcVar7 * 4);
                in_a1 = nid_objs + iVar3 * 0x18;
                iVar5 = (int)pcVar8 - *(int *)(nid_objs + iVar3 * 0x18 + 0xc);
                if (iVar5 == 0) goto LAB_004c3b30;
LAB_004c3b98:
              } while (iVar5 < 0);
            } while( true );
          }
LAB_004c3c0c:
          iVar3 = *(int *)(nid_objs + iVar3 * 0x18 + 8);
          pcVar6 = in_a2;
          goto LAB_004c39e4;
        }
LAB_004c3a78:
        iVar3 = 0;
        pcVar6 = in_a2;
        goto LAB_004c39e4;
      }
    }
  }
  else {
    if (uVar2 < 0x398) {
      puVar4 = nid_objs + uVar2 * 0x18;
      if (*(int *)(nid_objs + uVar2 * 0x18 + 8) != 0) goto LAB_004c3994;
      local_68 = (code *)0x140;
    }
    else {
      pcVar6 = in_a2;
      if (added == 0) goto LAB_004c3acc;
      in_a1 = (char *)&local_4c;
      local_4c = (void *)0x3;
      local_48 = &local_44;
      local_3c = uVar2;
      iVar3 = (*(code *)PTR_lh_retrieve_006a73b0)();
      if (iVar3 != 0) {
        puVar4 = *(undefined1 **)(iVar3 + 4);
        if (puVar4 != (undefined1 *)0x0) goto LAB_004c399c;
        goto LAB_004c3a78;
      }
      local_68 = (code *)0x14e;
    }
    in_a3 = "obj_dat.c";
    pcVar6 = &DAT_00000065;
    in_a1 = (char *)0x67;
    (*(code *)PTR_ERR_put_error_006a7f34)(8);
  }
LAB_004c3acc:
  puVar4 = (undefined1 *)0x0;
  iVar3 = 0;
LAB_004c39e4:
  (*(code *)PTR_ASN1_OBJECT_free_006a7004)(puVar4);
  if (local_2c == *(int *)puVar1) {
    return iVar3;
  }
  iVar3 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (0 < (int)pcVar6) {
    pcVar8 = (char *)0x0;
    do {
      while( true ) {
        pcVar7 = (char *)((int)(pcVar6 + (int)pcVar8) / 2);
        ppvVar9 = (void **)((int)in_a3 * (int)pcVar7 + (int)in_a1);
        iVar5 = (*local_68)(iVar3,ppvVar9);
        if (-1 < iVar5) break;
        pcVar6 = pcVar7;
        if ((int)pcVar7 <= (int)pcVar8) goto LAB_004c3ce0;
      }
      pcVar8 = pcVar7 + 1;
      if (iVar5 == 0) {
        return (int)ppvVar9;
      }
    } while ((int)pcVar8 < (int)pcVar6);
LAB_004c3ce0:
    if (iVar5 == 0) {
      return (int)ppvVar9;
    }
  }
  return 0;
}

