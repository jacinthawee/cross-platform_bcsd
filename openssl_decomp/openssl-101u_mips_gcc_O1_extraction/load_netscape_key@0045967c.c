
int load_netscape_key(undefined4 param_1,int *param_2,int *param_3,int *param_4,int param_5)

{
  bool bVar1;
  undefined *puVar2;
  int iVar3;
  int iVar4;
  int iVar5;
  undefined4 uVar6;
  uint uVar7;
  uint *puVar8;
  int *piVar9;
  int *piVar10;
  int *piVar11;
  char *pcVar12;
  int iStackY_7c;
  int local_30;
  uint *local_2c;
  
  puVar2 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(uint **)PTR___stack_chk_guard_006a9ae8;
  pcVar12 = (char *)param_2;
  piVar9 = param_3;
  iVar3 = (*(code *)PTR_BUF_MEM_new_006a749c)();
  iVar4 = (*(code *)PTR_EVP_PKEY_new_006a7620)();
  piVar10 = piVar9;
  if ((iVar3 != 0) && (iVar4 != 0)) {
    piVar11 = (int *)0x0;
    do {
      pcVar12 = (char *)(piVar11 + 0xa00);
      iVar5 = (*(code *)PTR_BUF_MEM_grow_clean_006a7b40)(iVar3);
      piVar10 = piVar9;
      if (iVar5 == 0) goto LAB_0045974c;
      piVar9 = (int *)0x2800;
      iVar5 = (*(code *)PTR_BIO_read_006a74c0)(param_2,*(int *)(iVar3 + 4) + (int)piVar11);
      piVar10 = (int *)((int)piVar11 + iVar5);
      if (iVar5 == 0) {
        local_30 = *(int *)(iVar3 + 4);
        pcVar12 = (char *)&local_30;
        piVar9 = (int *)(*(code *)PTR_d2i_RSA_NET_006a7b44)(0,pcVar12,piVar10,0,param_5 == 8);
        if (piVar9 == (int *)0x0) goto LAB_0045974c;
        (*(code *)PTR_BUF_MEM_free_006a7494)(iVar3);
        (*(code *)PTR_EVP_PKEY_set1_RSA_006a7624)(iVar4);
        goto LAB_0045976c;
      }
      piVar11 = piVar10;
    } while (-1 < iVar5);
    pcVar12 = "Error reading %s %s";
    (*(code *)PTR_BIO_printf_006a6e38)(param_1,"Error reading %s %s",param_4,param_3);
    piVar10 = param_4;
  }
LAB_0045974c:
  piVar9 = (int *)pcVar12;
  (*(code *)PTR_BUF_MEM_free_006a7494)(iVar3);
  (*(code *)PTR_EVP_PKEY_free_006a6e78)(iVar4);
  iVar4 = 0;
LAB_0045976c:
  if (local_2c == *(uint **)puVar2) {
    return iVar4;
  }
  puVar8 = local_2c;
  (*(code *)PTR___stack_chk_fail_006a9ab0)();
  if (piVar9 == (int *)0x0) {
    return 0;
  }
  iVar4 = 0;
  uVar6 = (*(code *)PTR_X509V3_parse_list_006a7b48)(piVar9);
  iStackY_7c = 1;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar6);
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(uVar6,iVar4);
      pcVar12 = *(char **)(iVar3 + 4);
      if (*pcVar12 == '-') {
        pcVar12 = pcVar12 + 1;
        bVar1 = false;
      }
      else if (*pcVar12 == '+') {
        pcVar12 = pcVar12 + 1;
        bVar1 = true;
      }
      else {
        bVar1 = true;
      }
      iVar3 = *piVar10;
      piVar9 = piVar10;
      while (iVar3 != 0) {
        iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar12);
        if (iVar3 == 0) {
          uVar7 = ~piVar9[2] & *puVar8;
          *puVar8 = uVar7;
          if (bVar1) {
            *puVar8 = uVar7 | piVar9[1];
          }
          else {
            *puVar8 = ~piVar9[1] & uVar7;
          }
          goto LAB_00459948;
        }
        piVar9 = piVar9 + 3;
        iVar3 = *piVar9;
      }
      iStackY_7c = 0;
LAB_00459948:
      iVar4 = iVar4 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar6);
    } while (iVar4 < iVar3);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar6,PTR_X509V3_conf_free_006a7b4c);
  return iStackY_7c;
}

