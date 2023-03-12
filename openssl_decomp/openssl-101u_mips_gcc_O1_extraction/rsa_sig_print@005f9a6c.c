
uint rsa_sig_print(undefined4 param_1,int *param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  uint uVar3;
  undefined4 *puVar4;
  undefined4 *unaff_s5;
  char *unaff_s6;
  int *piVar5;
  undefined4 local_30;
  int local_2c;
  
  puVar1 = PTR___stack_chk_guard_006a9ae8;
  local_2c = *(int *)PTR___stack_chk_guard_006a9ae8;
  iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*param_2);
  if (iVar2 != 0x390) {
    if (param_3 != 0) goto LAB_005f9ae0;
    iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
    uVar3 = (uint)(0 < iVar2);
    goto LAB_005f9af8;
  }
  puVar4 = (undefined4 *)param_2[1];
  if (puVar4 == (undefined4 *)0x0) {
LAB_005f9c18:
    iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1," (INVALID PSS PARAMETERS)\n");
    uVar3 = (uint)(0 < iVar2);
    if (uVar3 != 0) goto LAB_005f9c08;
    goto LAB_005f9af8;
  }
  unaff_s5 = (undefined4 *)*puVar4;
  unaff_s6 = (char *)&local_30;
  if (unaff_s5 != (undefined4 *)&SUB_00000010) goto LAB_005f9c18;
  local_30 = ((undefined4 *)puVar4[1])[2];
  param_2 = (int *)(*(code *)PTR_d2i_RSA_PSS_PARAMS_006a972c)(0,unaff_s6,*(undefined4 *)puVar4[1]);
  if (param_2 == (int *)0x0) goto LAB_005f9c18;
  puVar4 = (undefined4 *)param_2[1];
  if (puVar4 == (undefined4 *)0x0) {
LAB_005f9b98:
    unaff_s5 = (undefined4 *)0x0;
  }
  else {
    piVar5 = (int *)puVar4[1];
    iVar2 = (*(code *)PTR_OBJ_obj2nid_006a712c)(*puVar4);
    if (((iVar2 != 0x38f) || (piVar5 == (int *)0x0)) || (*piVar5 != 0x10)) goto LAB_005f9b98;
    local_30 = ((undefined4 *)piVar5[1])[2];
    unaff_s5 = (undefined4 *)
               (*(code *)PTR_d2i_X509_ALGOR_006a8dc4)(0,unaff_s6,*(undefined4 *)piVar5[1]);
  }
  unaff_s6 = "-check_ss_sig";
  iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n");
  if (((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_4,0x80), iVar2 != 0)
      ) && (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Hash Algorithm: "), 0 < iVar2)) {
    if ((undefined4 *)*param_2 == (undefined4 *)0x0) {
      iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"sha1 (default)");
    }
    else {
      iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_1,*(undefined4 *)*param_2);
    }
    if (((0 < iVar2) && (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"\n"), 0 < iVar2)) &&
       ((iVar2 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_4,0x80), iVar2 != 0 &&
        (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Mask Algorithm: "), 0 < iVar2)))) {
      if ((undefined4 *)param_2[1] == (undefined4 *)0x0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"mgf1 with sha1 (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_1,*(undefined4 *)param_2[1]);
        if ((iVar2 < 1) || (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1," with "), iVar2 < 1))
        goto LAB_005f9bd8;
        if (unaff_s5 == (undefined4 *)0x0) goto LAB_005f9ed4;
        iVar2 = (*(code *)PTR_i2a_ASN1_OBJECT_006a702c)(param_1,*unaff_s5);
      }
      if (0 < iVar2) goto LAB_005f9d40;
    }
  }
LAB_005f9bd8:
  (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(param_2);
  uVar3 = 0;
  if (unaff_s5 == (undefined4 *)0x0) goto LAB_005f9af8;
  do {
    (*(code *)PTR_X509_ALGOR_free_006a7ea4)(unaff_s5);
    if (uVar3 == 0) goto LAB_005f9af8;
LAB_005f9c08:
    do {
      uVar3 = 1;
      if (param_3 != 0) {
LAB_005f9ae0:
        uVar3 = (*(code *)PTR_X509_signature_dump_006a9728)(param_1,param_3,param_4);
      }
LAB_005f9af8:
      if (local_2c == *(int *)puVar1) {
        return uVar3;
      }
      (*(code *)PTR___stack_chk_fail_006a9ab0)();
LAB_005f9ed4:
      iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"INVALID");
      if (iVar2 < 1) goto LAB_005f9bd8;
LAB_005f9d40:
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,(undefined4 *)((int)unaff_s6 + -0x4d1c));
      iVar2 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_4,0x80);
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Salt Length: 0x"), iVar2 < 1))
      goto LAB_005f9bd8;
      if (param_2[2] == 0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"14 (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(param_1);
      }
      if (iVar2 < 1) goto LAB_005f9bd8;
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,(undefined4 *)((int)unaff_s6 + -0x4d1c));
      iVar2 = (*(code *)PTR_BIO_indent_006a86ac)(param_1,param_4,0x80);
      if ((iVar2 == 0) ||
         (iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"Trailer Field: 0x"), iVar2 < 1))
      goto LAB_005f9bd8;
      if (param_2[3] == 0) {
        iVar2 = (*(code *)PTR_BIO_puts_006a6f58)(param_1,"BC (default)");
      }
      else {
        iVar2 = (*(code *)PTR_i2a_ASN1_INTEGER_006a75f0)(param_1);
      }
      if (iVar2 < 1) goto LAB_005f9bd8;
      (*(code *)PTR_BIO_puts_006a6f58)(param_1,(undefined4 *)((int)unaff_s6 + -0x4d1c));
      (*(code *)PTR_RSA_PSS_PARAMS_free_006a971c)(param_2);
      uVar3 = 1;
    } while (unaff_s5 == (undefined4 *)0x0);
  } while( true );
}

