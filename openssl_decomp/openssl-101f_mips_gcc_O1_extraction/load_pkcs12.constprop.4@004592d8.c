
undefined4
load_pkcs12_constprop_4
          (undefined4 param_1,undefined4 param_2,undefined4 param_3,code *param_4,undefined4 param_5
          ,undefined4 param_6,undefined4 param_7)

{
  undefined *puVar1;
  int iVar2;
  int iVar3;
  undefined4 uVar4;
  char *pcVar5;
  uint uVar6;
  uint uVar7;
  char acStack_42c [1024];
  char *local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(char **)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_d2i_PKCS12_bio_006a838c)(param_2,0);
  if (iVar2 == 0) {
    (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Error loading PKCS12 file for %s\n",param_3);
    uVar4 = 0;
    goto LAB_004593b0;
  }
  iVar3 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar2,"",0);
  if ((iVar3 == 0) && (iVar3 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar2,0,0), iVar3 == 0)) {
    if (param_4 == (code *)0x0) {
      param_4 = password_callback;
    }
    pcVar5 = acStack_42c;
    iVar3 = (*param_4)(pcVar5,0x400,0,param_5);
    if (iVar3 < 0) {
      (*(code *)PTR_BIO_printf_006a7f38)(param_1,"Passpharse callback error for %s\n",param_3);
      uVar4 = 0;
    }
    else {
      if (iVar3 < 0x400) {
        acStack_42c[iVar3] = '\0';
      }
      iVar3 = (*(code *)PTR_PKCS12_verify_mac_006a8390)(iVar2,pcVar5,iVar3);
      if (iVar3 != 0) goto LAB_0045937c;
      (*(code *)PTR_BIO_printf_006a7f38)
                (param_1,"Mac verify error (wrong password?) in PKCS12 file for %s\n",param_3);
      uVar4 = 0;
    }
  }
  else {
    pcVar5 = "";
LAB_0045937c:
    uVar4 = (*(code *)PTR_PKCS12_parse_006a8c40)(iVar2,pcVar5,param_6,param_7,0);
  }
  (*(code *)PTR_PKCS12_free_006a837c)(iVar2);
LAB_004593b0:
  if (local_2c == *(char **)puVar1) {
    return uVar4;
  }
  pcVar5 = local_2c;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  if (pcVar5 != (char *)0x0) {
    uVar7 = (uint)*pcVar5;
    uVar6 = uVar7 & 0xffffffdf;
    if (uVar6 != 0x44) {
      if (uVar6 == 0x54) {
        uVar4 = 2;
      }
      else if (uVar6 == 0x4e) {
        uVar4 = 4;
      }
      else if (uVar6 == 0x53) {
        uVar4 = 6;
      }
      else if (uVar6 == 0x4d) {
        uVar4 = 0xb;
      }
      else if ((uVar7 == 0x31) || (iVar2 = (*(code *)PTR_strcmp_006aac20)(), iVar2 == 0)) {
        uVar4 = 5;
      }
      else {
        iVar2 = (*(code *)PTR_strcmp_006aac20)(pcVar5,"pkcs12");
        uVar4 = 5;
        if (((iVar2 != 0) &&
            (((((uVar7 & 0xff) != 0x50 && ((uVar7 & 0xff) != 0x70)) || (pcVar5[1] != '1')) ||
             ((pcVar5[2] != '2' || (uVar4 = 5, pcVar5[3] != '\0')))))) && (uVar4 = 7, uVar6 != 0x45)
           ) {
          if (uVar6 == 0x50) {
            uVar4 = 0xc;
            if ((pcVar5[1] & 0xdfU) != 0x56) {
              uVar4 = 3;
            }
          }
          else {
            uVar4 = 0;
          }
        }
      }
      return uVar4;
    }
    return 1;
  }
  return 0;
}

