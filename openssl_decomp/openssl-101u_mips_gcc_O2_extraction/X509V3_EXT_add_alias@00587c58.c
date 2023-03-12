
int X509V3_EXT_add_alias(int nid_to,int nid_from)

{
  undefined *puVar1;
  int *piVar2;
  int **ppiVar3;
  int *piVar4;
  int *piVar5;
  int *piVar6;
  undefined4 uVar7;
  int *piVar8;
  undefined4 uVar9;
  int iVar10;
  int iVar11;
  int iVar12;
  int *piVar13;
  int *local_58;
  int local_54 [14];
  int local_1c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_1c = *(int *)PTR___stack_chk_guard_006a9ae8;
  local_58 = local_54;
  if (-1 < nid_from) {
    local_54[0] = nid_from;
    ppiVar3 = (int **)(*(code *)PTR_OBJ_bsearch__006a8368)
                                (&local_58,standard_exts,0x28,4,ext_cmp_BSEARCH_CMP_FN);
    if (ppiVar3 == (int **)0x0) {
      if (ext_list != 0) {
        iVar10 = (*(code *)PTR_sk_find_006a8044)(ext_list,local_54);
        if (iVar10 != -1) {
          piVar13 = (int *)(*(code *)PTR_sk_value_006a6e24)(ext_list,iVar10);
          goto LAB_00587cd0;
        }
      }
    }
    else {
      piVar13 = *ppiVar3;
LAB_00587cd0:
      if (piVar13 != (int *)0x0) {
        piVar4 = (int *)(*(code *)PTR_CRYPTO_malloc_006a7008)(0x38,"v3_lib.c",0x91);
        if (piVar4 == (int *)0x0) {
          uVar9 = 0x6a;
          uVar7 = 0x92;
LAB_00587e90:
          (*(code *)PTR_ERR_put_error_006a7f34)(0x22,uVar9,0x41,"v3_lib.c",uVar7);
          iVar10 = 0;
        }
        else {
          piVar6 = piVar13;
          piVar2 = piVar4;
          do {
            piVar8 = piVar2;
            piVar5 = piVar6;
            piVar6 = piVar5 + 4;
            iVar12 = piVar5[1];
            iVar11 = piVar5[2];
            iVar10 = piVar5[3];
            *piVar8 = *piVar5;
            piVar8[1] = iVar12;
            piVar8[2] = iVar11;
            piVar8[3] = iVar10;
            piVar2 = piVar8 + 4;
          } while (piVar6 != piVar13 + 0xc);
          iVar10 = piVar5[5];
          piVar8[4] = *piVar6;
          piVar8[5] = iVar10;
          iVar10 = ext_list;
          *piVar4 = nid_to;
          piVar4[1] = piVar4[1] | 1;
          if (iVar10 == 0) {
            iVar10 = (*(code *)PTR_sk_new_006a806c)(ext_cmp);
            ext_list = iVar10;
            if (iVar10 == 0) {
              uVar9 = 0x68;
              uVar7 = 0x4d;
              goto LAB_00587e90;
            }
          }
          iVar10 = (*(code *)PTR_sk_push_006a6fa8)(iVar10,piVar4);
          if (iVar10 == 0) {
            (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x68,0x41,"v3_lib.c",0x51);
          }
          else {
            iVar10 = 1;
          }
        }
        goto LAB_00587d74;
      }
    }
  }
  (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x6a,0x66,"v3_lib.c",0x8c);
  iVar10 = 0;
LAB_00587d74:
  if (local_1c == *(int *)puVar1) {
    return iVar10;
  }
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  iVar10 = (*(code *)PTR_sk_pop_free_006a7058)(ext_list,ext_list_free);
  ext_list = 0;
  return iVar10;
}

