
void * X509V3_EXT_d2i(X509_EXTENSION *ext)

{
  bool bVar1;
  undefined *puVar2;
  int *piVar3;
  int iVar4;
  void *pvVar5;
  int iVar6;
  X509_EXTENSION *pXVar7;
  int **ppiVar8;
  int *piVar9;
  X509_EXTENSION *pXVar10;
  ASN1_OCTET_STRING *pAVar11;
  stack_st_X509_EXTENSION **ppsVar12;
  stack_st_X509_EXTENSION *psVar13;
  int **in_a1;
  undefined1 *puVar14;
  int **ppiVar15;
  int *in_a2;
  undefined4 uVar16;
  int *in_a3;
  int **ppiVar17;
  uint uVar18;
  int **unaff_s2;
  undefined1 *unaff_s3;
  code *pcStack_e8;
  int **ppiStack_d8;
  int *apiStack_d4 [14];
  stack_st_X509_EXTENSION **ppsStack_9c;
  undefined *puStack_98;
  X509_EXTENSION *pXStack_94;
  int **ppiStack_90;
  undefined1 *puStack_8c;
  int **local_58;
  int *local_54 [14];
  int local_1c;
  
  puStack_98 = PTR___stack_chk_guard_006aabf0;
  local_1c = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar3 = (int *)(*(code *)PTR_OBJ_obj2nid_006a822c)(ext->object);
  if ((piVar3 == (int *)0x0) || (unaff_s2 = local_54, local_58 = unaff_s2, (int)piVar3 < 0)) {
LAB_0058ad5c:
    pvVar5 = (void *)0x0;
  }
  else {
    in_a3 = (int *)&SUB_00000004;
    in_a2 = (int *)0x28;
    puVar14 = standard_exts;
    local_54[0] = piVar3;
    piVar3 = (int *)(*(code *)PTR_OBJ_bsearch__006a9488)(&local_58);
    if (piVar3 == (int *)0x0) {
      unaff_s3 = &_ITM_registerTMCloneTable;
      in_a1 = (int **)puVar14;
      if ((ext_list == 0) ||
         (in_a1 = unaff_s2, puVar14 = (undefined1 *)(*(code *)PTR_sk_find_006a906c)(),
         (int **)puVar14 == (int **)0xffffffff)) goto LAB_0058ad5c;
      iVar4 = (*(code *)PTR_sk_value_006a7f24)(ext_list);
    }
    else {
      iVar4 = *piVar3;
    }
    in_a1 = (int **)puVar14;
    if (iVar4 == 0) goto LAB_0058ad5c;
    pAVar11 = ext->value;
    local_54[0] = (int *)pAVar11->data;
    in_a3 = *(int **)(iVar4 + 8);
    if (in_a3 == (int *)0x0) {
      in_a2 = (int *)pAVar11->length;
      in_a1 = unaff_s2;
      pvVar5 = (void *)(**(code **)(iVar4 + 0x14))(0);
    }
    else {
      in_a2 = (int *)pAVar11->length;
      in_a1 = unaff_s2;
      pvVar5 = (void *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0);
    }
  }
  if (local_1c == *(int *)puStack_98) {
    return pvVar5;
  }
  iVar4 = local_1c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar2 = PTR___stack_chk_guard_006aabf0;
  ppsStack_9c = *(stack_st_X509_EXTENSION ***)PTR___stack_chk_guard_006aabf0;
  ppiVar15 = in_a1;
  piVar3 = in_a2;
  piVar9 = in_a3;
  pXStack_94 = ext;
  ppiStack_90 = unaff_s2;
  puStack_8c = unaff_s3;
  if (iVar4 == 0) {
    if (in_a3 != (int *)0x0) goto LAB_0058ae80;
LAB_0058ae88:
    ppiVar17 = ppiVar15;
    if (in_a2 == (int *)0x0) {
LAB_0058aecc:
      ppiVar15 = ppiVar17;
      pvVar5 = (void *)0x0;
    }
    else {
      pvVar5 = (void *)0x0;
      *in_a2 = -1;
    }
  }
  else {
    if (in_a3 != (int *)0x0) {
      ppiVar17 = (int **)(*in_a3 + 1);
      if ((int)ppiVar17 < 1) {
        ppiVar17 = (int **)0x0;
      }
      for (; iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar4), (int)ppiVar17 < iVar6;
          ppiVar17 = (int **)((int)ppiVar17 + 1)) {
        ppiVar15 = ppiVar17;
        pXVar7 = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a7f24)(iVar4);
        ppiVar8 = (int **)(*(code *)PTR_OBJ_obj2nid_006a822c)(pXVar7->object);
        if (ppiVar8 == in_a1) {
          *in_a3 = (int)ppiVar17;
          goto LAB_0058aed8;
        }
      }
LAB_0058ae80:
      *in_a3 = -1;
      in_a3 = piVar9;
      goto LAB_0058ae88;
    }
    ppiVar17 = (int **)0x0;
    pXVar7 = (X509_EXTENSION *)0x0;
    iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
    piVar9 = in_a3;
    if (0 < iVar6) {
      do {
        ppiVar15 = ppiVar17;
        pXVar10 = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a7f24)(iVar4);
        ppiVar8 = (int **)(*(code *)PTR_OBJ_obj2nid_006a822c)(pXVar10->object);
        if ((in_a1 == ppiVar8) && (bVar1 = pXVar7 != (X509_EXTENSION *)0x0, pXVar7 = pXVar10, bVar1)
           ) {
          ppiVar17 = ppiVar15;
          if (in_a2 == (int *)0x0) goto LAB_0058aecc;
          pvVar5 = (void *)0x0;
          *in_a2 = -2;
          goto LAB_0058ae98;
        }
        ppiVar17 = (int **)((int)ppiVar17 + 1);
        iVar6 = (*(code *)PTR_sk_num_006a7f2c)(iVar4);
        piVar9 = in_a3;
      } while ((int)ppiVar17 < iVar6);
    }
    in_a3 = piVar9;
    if (pXVar7 == (X509_EXTENSION *)0x0) goto LAB_0058ae88;
LAB_0058aed8:
    ppiVar17 = ppiVar15;
    in_a3 = piVar9;
    if (in_a2 != (int *)0x0) {
      iVar4 = X509_EXTENSION_get_critical(pXVar7);
      *in_a2 = iVar4;
      ppiVar17 = ppiVar15;
      in_a3 = piVar9;
    }
    piVar9 = (int *)(*(code *)PTR_OBJ_obj2nid_006a822c)(pXVar7->object);
    if ((piVar9 == (int *)0x0) || (ppiVar15 = apiStack_d4, ppiStack_d8 = ppiVar15, (int)piVar9 < 0))
    goto LAB_0058aecc;
    in_a3 = (int *)&SUB_00000004;
    piVar3 = (int *)0x28;
    puVar14 = standard_exts;
    pcStack_e8 = ext_cmp_BSEARCH_CMP_FN;
    apiStack_d4[0] = piVar9;
    piVar9 = (int *)(*(code *)PTR_OBJ_bsearch__006a9488)(&ppiStack_d8);
    if (piVar9 == (int *)0x0) {
      ppiVar17 = (int **)puVar14;
      if ((ext_list == 0) ||
         (ppiVar17 = ppiVar15, puVar14 = (undefined1 *)(*(code *)PTR_sk_find_006a906c)(),
         (int **)puVar14 == (int **)0xffffffff)) goto LAB_0058aecc;
      iVar4 = (*(code *)PTR_sk_value_006a7f24)(ext_list);
    }
    else {
      iVar4 = *piVar9;
    }
    ppiVar17 = (int **)puVar14;
    if (iVar4 == 0) goto LAB_0058aecc;
    pAVar11 = pXVar7->value;
    apiStack_d4[0] = (int *)pAVar11->data;
    in_a3 = *(int **)(iVar4 + 8);
    if (in_a3 == (int *)0x0) {
      piVar3 = (int *)pAVar11->length;
      pvVar5 = (void *)(**(code **)(iVar4 + 0x14))(0);
    }
    else {
      piVar3 = (int *)pAVar11->length;
      pvVar5 = (void *)(*(code *)PTR_ASN1_item_d2i_006a9798)(0);
    }
  }
LAB_0058ae98:
  if (ppsStack_9c == *(stack_st_X509_EXTENSION ***)puVar2) {
    return pvVar5;
  }
  ppsVar12 = ppsStack_9c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  uVar18 = (uint)pcStack_e8 & 0xf;
  if (uVar18 != 1) {
    iVar4 = X509v3_get_ext_by_NID(*ppsVar12,(int)ppiVar15,-1);
    if (-1 < iVar4) {
      if (uVar18 == 4) {
        return (void *)0x1;
      }
      if (uVar18 == 0) {
        uVar16 = 0x91;
        goto LAB_0058b104;
      }
      if (uVar18 != 5) {
        pXVar7 = X509V3_EXT_i2d((int)ppiVar15,(int)in_a3,piVar3);
        if (pXVar7 != (X509_EXTENSION *)0x0) {
          uVar16 = (*(code *)PTR_sk_value_006a7f24)(*ppsVar12,iVar4);
          (*(code *)PTR_X509_EXTENSION_free_006a8268)(uVar16);
          iVar4 = (*(code *)PTR_sk_set_006a9478)(*ppsVar12,iVar4,pXVar7);
          if (iVar4 == 0) {
            return (void *)0xffffffff;
          }
          return (void *)0x1;
        }
        goto LAB_0058b238;
      }
      iVar4 = (*(code *)PTR_sk_delete_006a8398)(*ppsVar12,iVar4);
      goto joined_r0x0058b228;
    }
    if (uVar18 == 3) {
      uVar16 = 0x66;
LAB_0058b104:
      if (((uint)pcStack_e8 & 0x10) != 0) {
        return (void *)0x0;
      }
      (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8c,uVar16,"v3_lib.c",0x131);
      return (void *)0x0;
    }
    uVar16 = 0x66;
    if (uVar18 == 5) goto LAB_0058b104;
  }
  pXVar7 = X509V3_EXT_i2d((int)ppiVar15,(int)in_a3,piVar3);
  if (pXVar7 == (X509_EXTENSION *)0x0) {
LAB_0058b238:
    (*(code *)PTR_ERR_put_error_006a9030)(0x22,0x8c,0x90,"v3_lib.c",0x11e);
    return (void *)0x0;
  }
  psVar13 = *ppsVar12;
  if (psVar13 == (stack_st_X509_EXTENSION *)0x0) {
    psVar13 = (stack_st_X509_EXTENSION *)(*(code *)PTR_sk_new_null_006a80a4)();
    *ppsVar12 = psVar13;
    if (psVar13 == (stack_st_X509_EXTENSION *)0x0) {
      return (void *)0xffffffff;
    }
  }
  iVar4 = (*(code *)PTR_sk_push_006a80a8)(psVar13,pXVar7);
joined_r0x0058b228:
  if (iVar4 != 0) {
    return (void *)0x1;
  }
  return (void *)0xffffffff;
}

