
undefined4 set_cert_ex(uint *param_1,int param_2)

{
  bool bVar1;
  undefined4 uVar2;
  int iVar3;
  uint uVar4;
  char *pcVar5;
  int iVar6;
  int *piVar7;
  undefined4 uStack_2c;
  
  if (param_2 == 0) {
    return 0;
  }
  iVar6 = 0;
  uVar2 = (*(code *)PTR_X509V3_parse_list_006a7b48)(param_2);
  uStack_2c = 1;
  iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar2);
  if (0 < iVar3) {
    do {
      iVar3 = (*(code *)PTR_sk_value_006a6e24)(uVar2,iVar6);
      pcVar5 = *(char **)(iVar3 + 4);
      piVar7 = (int *)cert_tbl_16879;
      iVar3 = cert_tbl_16879._0_4_;
      if (*pcVar5 == '-') {
        pcVar5 = pcVar5 + 1;
        bVar1 = false;
      }
      else if (*pcVar5 == '+') {
        pcVar5 = pcVar5 + 1;
        bVar1 = true;
      }
      else {
        bVar1 = true;
      }
      while (iVar3 != 0) {
        iVar3 = (*(code *)PTR_strcasecmp_006a9a18)(pcVar5);
        if (iVar3 == 0) {
          uVar4 = ~piVar7[2] & *param_1;
          *param_1 = uVar4;
          if (bVar1) {
            *param_1 = uVar4 | piVar7[1];
          }
          else {
            *param_1 = ~piVar7[1] & uVar4;
          }
          goto LAB_00459948;
        }
        piVar7 = piVar7 + 3;
        iVar3 = *piVar7;
      }
      uStack_2c = 0;
LAB_00459948:
      iVar6 = iVar6 + 1;
      iVar3 = (*(code *)PTR_sk_num_006a6e2c)(uVar2);
    } while (iVar6 < iVar3);
  }
  (*(code *)PTR_sk_pop_free_006a7058)(uVar2,PTR_X509V3_conf_free_006a7b4c);
  return uStack_2c;
}

