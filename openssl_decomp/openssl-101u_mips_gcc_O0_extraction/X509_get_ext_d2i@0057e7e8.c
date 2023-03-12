
void * X509_get_ext_d2i(X509 *x,int nid,int *crit,int *idx)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  X509_EXTENSION *pXVar4;
  int *piVar5;
  void *pvVar6;
  X509_EXTENSION *pXVar7;
  ASN1_OCTET_STRING *pAVar8;
  stack_st_X509_EXTENSION *psVar9;
  stack_st_X509_EXTENSION **ppsVar10;
  undefined1 *puVar11;
  int **ppiVar12;
  int *piVar13;
  undefined4 uVar14;
  int **ppiVar15;
  uint uVar16;
  uint uStack_70;
  int **ppiStack_60;
  int *apiStack_5c [14];
  stack_st_X509_EXTENSION **ppsStack_24;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  psVar9 = x->cert_info->extensions;
  ppsStack_24 = *(stack_st_X509_EXTENSION ***)PTR___stack_chk_guard_006a9ae8;
  ppiVar12 = (int **)nid;
  piVar13 = crit;
  piVar5 = idx;
  if (psVar9 == (stack_st_X509_EXTENSION *)0x0) {
    if (idx != (int *)0x0) goto LAB_00588110;
LAB_00588118:
    ppiVar15 = ppiVar12;
    if (crit == (int *)0x0) {
LAB_0058815c:
      ppiVar12 = ppiVar15;
      pvVar6 = (void *)0x0;
    }
    else {
      pvVar6 = (void *)0x0;
      *crit = -1;
    }
  }
  else {
    if (idx != (int *)0x0) {
      ppiVar15 = (int **)(*idx + 1);
      if ((int)ppiVar15 < 1) {
        ppiVar15 = (int **)0x0;
      }
      for (; iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar9), (int)ppiVar15 < iVar3;
          ppiVar15 = (int **)((int)ppiVar15 + 1)) {
        ppiVar12 = ppiVar15;
        pXVar4 = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a6e24)(psVar9);
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pXVar4->object);
        if (iVar3 == nid) {
          *idx = (int)ppiVar15;
          goto LAB_00588168;
        }
      }
LAB_00588110:
      *idx = -1;
      idx = piVar5;
      goto LAB_00588118;
    }
    ppiVar15 = (int **)0x0;
    pXVar4 = (X509_EXTENSION *)0x0;
    iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar9);
    piVar5 = idx;
    if (0 < iVar3) {
      do {
        ppiVar12 = ppiVar15;
        pXVar7 = (X509_EXTENSION *)(*(code *)PTR_sk_value_006a6e24)(psVar9);
        iVar3 = (*(code *)PTR_OBJ_obj2nid_006a712c)(pXVar7->object);
        if ((nid == iVar3) && (bVar1 = pXVar4 != (X509_EXTENSION *)0x0, pXVar4 = pXVar7, bVar1)) {
          ppiVar15 = ppiVar12;
          if (crit == (int *)0x0) goto LAB_0058815c;
          pvVar6 = (void *)0x0;
          *crit = -2;
          goto LAB_00588128;
        }
        ppiVar15 = (int **)((int)ppiVar15 + 1);
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(psVar9);
        piVar5 = idx;
      } while ((int)ppiVar15 < iVar3);
    }
    idx = piVar5;
    if (pXVar4 == (X509_EXTENSION *)0x0) goto LAB_00588118;
LAB_00588168:
    ppiVar15 = ppiVar12;
    idx = piVar5;
    if (crit != (int *)0x0) {
      iVar3 = X509_EXTENSION_get_critical(pXVar4);
      *crit = iVar3;
      ppiVar15 = ppiVar12;
      idx = piVar5;
    }
    piVar5 = (int *)(*(code *)PTR_OBJ_obj2nid_006a712c)(pXVar4->object);
    if ((piVar5 == (int *)0x0) || (ppiVar12 = apiStack_5c, ppiStack_60 = ppiVar12, (int)piVar5 < 0))
    goto LAB_0058815c;
    idx = (int *)&SUB_00000004;
    piVar13 = (int *)0x28;
    puVar11 = standard_exts;
    uStack_70 = 0;
    apiStack_5c[0] = piVar5;
    piVar5 = (int *)(*(code *)PTR_OBJ_bsearch__006a8368)(&ppiStack_60);
    if (piVar5 == (int *)0x0) {
      ppiVar15 = (int **)puVar11;
      if ((ext_list == 0) ||
         (ppiVar15 = ppiVar12, puVar11 = (undefined1 *)(*(code *)PTR_sk_find_006a8044)(),
         (int **)puVar11 == (int **)0xffffffff)) goto LAB_0058815c;
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(ext_list);
    }
    else {
      iVar3 = *piVar5;
    }
    ppiVar15 = (int **)puVar11;
    if (iVar3 == 0) goto LAB_0058815c;
    pAVar8 = pXVar4->value;
    apiStack_5c[0] = (int *)pAVar8->data;
    idx = *(int **)(iVar3 + 8);
    if (idx == (int *)0x0) {
      piVar13 = (int *)pAVar8->length;
      pvVar6 = (void *)(**(code **)(iVar3 + 0x14))(0);
    }
    else {
      piVar13 = (int *)pAVar8->length;
      pvVar6 = (void *)(*(code *)PTR_ASN1_item_d2i_006a8674)(0);
    }
  }
LAB_00588128:
  if (ppsStack_24 == *(stack_st_X509_EXTENSION ***)puVar2) {
    return pvVar6;
  }
  ppsVar10 = ppsStack_24;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  uVar16 = uStack_70 & 0xf;
  if (uVar16 != 1) {
    iVar3 = X509v3_get_ext_by_NID(*ppsVar10,(int)ppiVar12,-1);
    if (-1 < iVar3) {
      if (uVar16 == 4) {
        return (void *)0x1;
      }
      if (uVar16 == 0) {
        uVar14 = 0x91;
        goto LAB_00588394;
      }
      if (uVar16 != 5) {
        pXVar4 = X509V3_EXT_i2d((int)ppiVar12,(int)idx,piVar13);
        if (pXVar4 != (X509_EXTENSION *)0x0) {
          uVar14 = (*(code *)PTR_sk_value_006a6e24)(*ppsVar10,iVar3);
          (*(code *)PTR_X509_EXTENSION_free_006a7168)(uVar14);
          iVar3 = (*(code *)PTR_sk_set_006a8358)(*ppsVar10,iVar3,pXVar4);
          if (iVar3 == 0) {
            return (void *)0xffffffff;
          }
          return (void *)0x1;
        }
        goto LAB_005884c8;
      }
      iVar3 = (*(code *)PTR_sk_delete_006a7288)(*ppsVar10,iVar3);
      goto joined_r0x005884b8;
    }
    if (uVar16 == 3) {
      uVar14 = 0x66;
LAB_00588394:
      if ((uStack_70 & 0x10) != 0) {
        return (void *)0x0;
      }
      (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8c,uVar14,"v3_lib.c",0x151);
      return (void *)0x0;
    }
    uVar14 = 0x66;
    if (uVar16 == 5) goto LAB_00588394;
  }
  pXVar4 = X509V3_EXT_i2d((int)ppiVar12,(int)idx,piVar13);
  if (pXVar4 == (X509_EXTENSION *)0x0) {
LAB_005884c8:
    (*(code *)PTR_ERR_put_error_006a7f34)(0x22,0x8c,0x90,"v3_lib.c",0x13b);
    return (void *)0x0;
  }
  psVar9 = *ppsVar10;
  if (psVar9 == (stack_st_X509_EXTENSION *)0x0) {
    psVar9 = (stack_st_X509_EXTENSION *)(*(code *)PTR_sk_new_null_006a6fa4)();
    *ppsVar10 = psVar9;
    if (psVar9 == (stack_st_X509_EXTENSION *)0x0) {
      return (void *)0xffffffff;
    }
  }
  iVar3 = (*(code *)PTR_sk_push_006a6fa8)(psVar9,pXVar4);
joined_r0x005884b8:
  if (iVar3 != 0) {
    return (void *)0x1;
  }
  return (void *)0xffffffff;
}

