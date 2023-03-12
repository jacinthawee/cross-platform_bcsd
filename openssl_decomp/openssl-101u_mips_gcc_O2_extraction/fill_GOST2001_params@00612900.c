
int * fill_GOST2001_params(undefined4 param_1,int param_2)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  int *piVar5;
  int unaff_s1;
  int unaff_s5;
  int local_3c;
  int local_38;
  int local_34;
  int local_30;
  int local_2c;
  int local_28;
  int local_24;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_3c = 0;
  local_38 = 0;
  local_34 = 0;
  local_30 = 0;
  local_2c = 0;
  local_28 = 0;
  local_24 = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_BN_CTX_new_006a794c)();
  if (iVar2 == 0) {
    piVar5 = (int *)0x0;
    ERR_GOST_error(0x65,0x41,"gost2001.c",0x2d);
    iVar2 = unaff_s1;
    goto LAB_00612a90;
  }
  (*(code *)PTR_BN_CTX_start_006a8528)(iVar2);
  local_3c = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  local_34 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  local_30 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  local_2c = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  local_28 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  local_38 = (*(code *)PTR_BN_CTX_get_006a852c)(iVar2);
  if ((((local_3c == 0) || (local_34 == 0)) || (local_30 == 0)) ||
     (((local_2c == 0 || (local_28 == 0)) || (local_38 == 0)))) {
    uVar4 = 0x39;
LAB_00612acc:
    ERR_GOST_error(0x65,0x41,"gost2001.c",uVar4);
  }
  else {
    iVar3 = *(int *)PTR_R3410_2001_paramset_006a95f8;
    piVar5 = (int *)PTR_R3410_2001_paramset_006a95f8;
    while (iVar3 != 0) {
      if (iVar3 == param_2) {
        iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_3c,piVar5[3]);
        if (((iVar3 == 0) ||
            (iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_34,piVar5[1]), iVar3 == 0)) ||
           (iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_30,piVar5[2]), iVar3 == 0)) {
          ERR_GOST_error(0x65,0x44,"gost2001.c",0x47);
          goto LAB_00612a6c;
        }
        param_2 = (*(code *)PTR_EC_GROUP_new_curve_GFp_006a8638)(local_3c,local_34,local_30,iVar2);
        if (param_2 != 0) {
          unaff_s5 = (*(code *)PTR_EC_POINT_new_006a7fc0)(param_2);
          if (unaff_s5 == 0) {
            piVar5 = (int *)0x0;
            ERR_GOST_error(0x65,0x41,"gost2001.c",0x53);
            goto LAB_00612c18;
          }
          iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_2c,piVar5[5]);
          if ((((iVar3 != 0) &&
               (iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_28,piVar5[6]), iVar3 != 0)) &&
              (iVar3 = (*(code *)PTR_EC_POINT_set_affine_coordinates_GFp_006a8634)
                                 (param_2,unaff_s5,local_2c,local_28,iVar2), iVar3 != 0)) &&
             (iVar3 = (*(code *)PTR_BN_hex2bn_006a70f0)(&local_38,piVar5[4]), iVar3 != 0)) {
            iVar3 = (*(code *)PTR_EC_GROUP_set_generator_006a863c)(param_2,unaff_s5,local_38,0);
            if (iVar3 != 0) goto LAB_00612cd4;
            uVar4 = 0x66;
            goto LAB_00612bec;
          }
          uVar4 = 0x5b;
          goto LAB_00612bec;
        }
        uVar4 = 0x4d;
        goto LAB_00612acc;
      }
      piVar5 = piVar5 + 7;
      iVar3 = *piVar5;
    }
    ERR_GOST_error(0x65,0x82,"gost2001.c",0x40);
  }
LAB_00612a6c:
  piVar5 = (int *)0x0;
  while( true ) {
    (*(code *)PTR_BN_CTX_end_006a8530)(iVar2);
    (*(code *)PTR_BN_CTX_free_006a7954)(iVar2);
LAB_00612a90:
    if (local_24 == *(int *)puVar1) break;
    (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_00612cd4:
    (*(code *)PTR_EC_GROUP_set_curve_name_006a862c)(param_2,*piVar5);
    iVar3 = (*(code *)PTR_EC_KEY_set_group_006a71cc)(param_1,param_2);
    if (iVar3 == 0) {
      uVar4 = 0x6b;
LAB_00612bec:
      piVar5 = (int *)0x0;
      ERR_GOST_error(0x65,0x44,"gost2001.c",uVar4);
    }
    else {
      piVar5 = (int *)0x1;
    }
    (*(code *)PTR_EC_POINT_free_006a7fac)(unaff_s5);
LAB_00612c18:
    (*(code *)PTR_EC_GROUP_free_006a719c)(param_2);
  }
  return piVar5;
}

