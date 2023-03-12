
undefined4 TS_CONF_set_digests(undefined4 param_1,undefined4 param_2,undefined4 param_3)

{
  int iVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  
  iVar1 = (*(code *)PTR_NCONF_get_string_006a7fa8)(param_1,param_2,"digests");
  if (iVar1 == 0) {
    iVar1 = 0;
    uVar4 = 0;
    (*(code *)PTR___fprintf_chk_006aaa8c)
              (*(undefined4 *)PTR_stderr_006aac00,1,"variable lookup failed for %s::%s\n",param_2,
               "digests");
  }
  else {
    iVar1 = (*(code *)PTR_X509V3_parse_list_006a8c34)(iVar1);
    if ((iVar1 == 0) || (iVar2 = (*(code *)PTR_sk_num_006a7f2c)(iVar1), iVar2 == 0)) {
LAB_005c8a64:
      uVar4 = 0;
      (*(code *)PTR___fprintf_chk_006aaa8c)
                (*(undefined4 *)PTR_stderr_006aac00,1,"invalid variable value for %s::%s\n",param_2,
                 "digests");
    }
    else {
      iVar2 = 0;
      do {
        iVar3 = (*(code *)PTR_sk_num_006a7f2c)(iVar1);
        if (iVar3 <= iVar2) {
          uVar4 = 1;
          goto LAB_005c8a94;
        }
        iVar3 = (*(code *)PTR_sk_value_006a7f24)(iVar1,iVar2);
        if (*(int *)(iVar3 + 8) == 0) {
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a802c)(*(undefined4 *)(iVar3 + 4));
        }
        else {
          iVar3 = (*(code *)PTR_EVP_get_digestbyname_006a802c)();
        }
        if (iVar3 == 0) goto LAB_005c8a64;
        iVar3 = TS_RESP_CTX_add_md(param_3,iVar3);
        iVar2 = iVar2 + 1;
      } while (iVar3 != 0);
      uVar4 = 0;
    }
  }
LAB_005c8a94:
  (*(code *)PTR_sk_pop_free_006a8158)(iVar1,PTR_X509V3_conf_free_006a8c38);
  return uVar4;
}

