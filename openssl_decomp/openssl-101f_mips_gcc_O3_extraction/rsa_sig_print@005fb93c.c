
uint rsa_sig_print(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_s5;
  undefined4 *unaff_s6;
  int *piVar5;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006aabf0;
  local_2c = *(int *)PTR___stack_chk_guard_006aabf0;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*param_2);
  if (iVar2 != 0x390) {
    if (param_3 != 0) goto LAB_005fb9b0;
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
    uVar3 = (uint)(0 < iVar2);
    goto LAB_005fb9c8;
  }
  puVar4 = (undefined4 *)param_2[1];
  if (puVar4 == (undefined4 *)0x0) {
LAB_005fbae8:
    iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1," (INVALID PSS PARAMETERS)\n");
    uVar3 = (uint)(0 < iVar2);
    if (uVar3 != 0) goto LAB_005fbad8;
    goto LAB_005fb9c8;
  }
  unaff_s5 = (undefined4 *)*puVar4;
  unaff_s6 = &local_30;
  if (unaff_s5 != (undefined4 *)&SUB_00000010) goto LAB_005fbae8;
  local_30 = ((undefined4 *)puVar4[1])[2];
  param_2 = (int *)(*(code *)PTR_d2i_RSA_PSS_PARAMS_006aa834)(0,unaff_s6,*(undefined4 *)puVar4[1]);
  if (param_2 == (int *)0x0) goto LAB_005fbae8;
  puVar4 = (undefined4 *)param_2[1];
  if (puVar4 == (undefined4 *)0x0) {
LAB_005fba68:
    unaff_s5 = (undefined4 *)0x0;
  }
  else {
    piVar5 = (int *)puVar4[1];
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar4);
    if ((iVar2 != 0x38f) || (*piVar5 != 0x10)) goto LAB_005fba68;
    puVar4 = (undefined4 *)piVar5[1];
    local_30 = puVar4[2];
    unaff_s5 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a9ee4)(0,unaff_s6,*puVar4);
  }
  unaff_s6 = (undefined4 *)0x640000;
  iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n");
  if (((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_4,0x80), iVar2 != 0)
      ) && (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"Hash Algorithm: "), 0 < iVar2)) {
    if ((undefined4 *)*param_2 == (undefined4 *)0x0) {
      iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"sha1 (default)");
    }
    else {
      iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_1,*(undefined4 *)*param_2);
    }
    if (((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"\n"), 0 < iVar2)) &&
       ((iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_4,0x80), iVar2 != 0 &&
        (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"Mask Algorithm: "), 0 < iVar2)))) {
      if ((undefined4 *)param_2[1] == (undefined4 *)0x0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"mgf1 with sha1 (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_1,*(undefined4 *)param_2[1]);
        if ((iVar2 < 1) || (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1," with "), iVar2 < 1))
        goto LAB_005fbaa8;
        if (unaff_s5 == (undefined4 *)0x0) goto LAB_005fbd9c;
        iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(param_1,*unaff_s5);
      }
      if (0 < iVar2) goto LAB_005fbc10;
    }
  }
LAB_005fbaa8:
  (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(param_2);
  uVar3 = 0;
  if (unaff_s5 == (undefined4 *)0x0) goto LAB_005fb9c8;
  do {
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(unaff_s5);
    if (uVar3 == 0) goto LAB_005fb9c8;
LAB_005fbad8:
    do {
      uVar3 = 1;
      if (param_3 != 0) {
LAB_005fb9b0:
        uVar3 = (*(code *)PTR_X509_signature_dump_006aa830)(param_1,param_3,param_4);
      }
LAB_005fb9c8:
      if (local_2c == *(int *)puVar1) {
        return uVar3;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005fbd9c:
      iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"INVALID");
      if (iVar2 < 1) goto LAB_005fbaa8;
LAB_005fbc10:
      (*(code *)PTR_BIO_puts_006a8058)(param_1,unaff_s6 + -0x114e);
      iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_4,0x80);
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"Salt Length: 0x"), iVar2 < 1))
      goto LAB_005fbaa8;
      if (param_2[2] == 0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"0x14 (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(param_1);
      }
      if (iVar2 < 1) goto LAB_005fbaa8;
      (*(code *)PTR_BIO_puts_006a8058)(param_1,unaff_s6 + -0x114e);
      iVar2 = (*(code *)PTR_BIO_indent_006a97d0)(param_1,param_4,0x80);
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"Trailer Field: 0x"), iVar2 < 1))
      goto LAB_005fbaa8;
      if (param_2[3] == 0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a8058)(param_1,"BC (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(param_1);
      }
      if (iVar2 < 1) goto LAB_005fbaa8;
      (*(code *)PTR_BIO_puts_006a8058)(param_1,unaff_s6 + -0x114e);
      (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(param_2);
      uVar3 = 1;
    } while (unaff_s5 == (undefined4 *)0x0);
  } while( true );
}

