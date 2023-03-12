
undefined4 ssl_ctx_make_profiles(int param_1,int *param_2)

{
  int iVar1;
  int iVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  undefined1 *puVar7;
  int iVar8;
  
  iVar1 = (*(code *)PTR_sk_new_null_006a80a4)();
  if (iVar1 == 0) {
    uVar6 = 0x16a;
    uVar5 = 0xc9;
  }
  else {
    iVar2 = (*(code *)PTR_strchr_006aab34)(param_1,0x3a);
    if (iVar2 == 0) goto LAB_004a8968;
    while (iVar8 = iVar2 - param_1, srtp_known_profiles._0_4_ != 0) {
      while( true ) {
        puVar7 = srtp_known_profiles;
        iVar4 = srtp_known_profiles._0_4_;
        while ((iVar3 = (*(code *)PTR_strlen_006aab30)(iVar4), iVar8 != iVar3 ||
               (iVar4 = (*(code *)PTR_strncmp_006aaa7c)(iVar4,param_1,iVar8), iVar4 != 0))) {
          puVar7 = (undefined1 *)((int)puVar7 + 8);
          iVar4 = *(int *)puVar7;
          if (iVar4 == 0) goto LAB_004a8988;
        }
        (*(code *)PTR_sk_push_006a80a8)(iVar1,puVar7);
        if (iVar2 == 0) {
          *param_2 = iVar1;
          return 0;
        }
        param_1 = iVar2 + 1;
        iVar2 = (*(code *)PTR_strchr_006aab34)(param_1,0x3a);
        if (iVar2 != 0) break;
LAB_004a8968:
        iVar8 = (*(code *)PTR_strlen_006aab30)(param_1);
        if (srtp_known_profiles._0_4_ == 0) goto LAB_004a8988;
      }
    }
LAB_004a8988:
    uVar6 = 0x16c;
    uVar5 = 0xd8;
  }
  (*(code *)PTR_ERR_put_error_006a9030)(0x14,0x135,uVar6,"d1_srtp.c",uVar5);
  return 1;
}

