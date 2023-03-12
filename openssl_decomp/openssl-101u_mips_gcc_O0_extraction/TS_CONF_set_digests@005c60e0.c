
undefined4 TS_CONF_set_digests(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a6ea8)(param_1,param_2,"digests");
  if (iVar1 == 0) {
    iVar1 = 0;
    uVar4 = 0;
    (*(code *)PTR___fprintf_chk_006a9980)
              (*(undefined4 *)PTR_stderr_006a9af8,1,"variable lookup failed for %s::%s\n",param_2,
               "digests");
  }
  else {
    iVar1 = (*(code *)PTR_X509V3_parse_list_006a7b48)(iVar1);
    if ((iVar1 == 0) || (iVar2 = (*(code *)PTR_sk_num_006a6e2c)(iVar1), iVar2 == 0)) {
LAB_005c61e4:
      uVar4 = 0;
      (*(code *)PTR___fprintf_chk_006a9980)
                (*(undefined4 *)PTR_stderr_006a9af8,1,"invalid variable value for %s::%s\n",param_2,
                 "digests");
    }
    else {
      iVar2 = 0;
      do {
        iVar3 = (*(code *)PTR_sk_num_006a6e2c)(iVar1);
        if (iVar3 <= iVar2) {
          uVar4 = 1;
          goto LAB_005c6214;
        }
        iVar3 = (*(code *)PTR_sk_value_006a6e24)(iVar1,iVar2);
        if (*(int *)(iVar3 + 8) == 0) {
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)(*(undefined4 *)(iVar3 + 4));
        }
        else {
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a6f2c)();
        }
        if (iVar3 == 0) goto LAB_005c61e4;
        iVar3 = TS_RESP_CTX_add_md(param_3,iVar3);
        iVar2 = iVar2 + 1;
      } while (iVar3 != 0);
      uVar4 = 0;
    }
  }
LAB_005c6214:
  (*(code *)PTR_sk_pop_free_006a7058)(iVar1,PTR_X509V3_conf_free_006a7b4c);
  return uVar4;
}

