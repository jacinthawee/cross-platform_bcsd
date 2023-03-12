
uint rsa_pub_encode(undefined4 param_1,int param_2,int param_3,undefined4 param_4)

{
  undefined *puVar1;
  int iVar2;
  int *piVar3;
  uint uVar4;
  int iVar5;
  undefined4 *puVar6;
  int unaff_s1;
  undefined4 *unaff_s5;
  undefined4 *unaff_s6;
  int *piVar7;
  undefined4 uStack_70;
  int iStack_6c;
  undefined *puStack_64;
  int iStack_60;
  undefined4 uStack_5c;
  int local_18;
  int local_14;
  
  puStack_64 = PTR___stack_chk_guard_006aabf0;
  local_18 = 0;
  local_14 = *(int *)PTR___stack_chk_guard_006aabf0;
  piVar3 = &local_18;
  iVar2 = (*(code *)PTR_i2d_RSAPublicKey_006a9f7c)(*(undefined4 *)(param_2 + 0x14));
  if (iVar2 < 1) {
    uVar4 = 0;
  }
  else {
    piVar3 = (int *)(*(code *)PTR_OBJ_nid2obj_006a8240)(6);
    param_4 = 0;
    param_3 = 5;
    uVar4 = (*(code *)PTR_X509_PUBKEY_set0_param_006a98c8)(param_1,piVar3,5,0);
    unaff_s1 = iVar2;
    if (uVar4 == 0) {
      (*(code *)PTR_CRYPTO_free_006a7f88)(local_18);
    }
    else {
      uVar4 = 1;
    }
  }
  if (local_14 == *(int *)puStack_64) {
    return uVar4;
  }
  iVar2 = local_14;
  (*(code *)PTR___stack_chk_fail_006aabb8)();
  puVar1 = PTR___stack_chk_guard_006aabf0;
  iStack_6c = *(int *)PTR___stack_chk_guard_006aabf0;
  iStack_60 = unaff_s1;
  uStack_5c = param_1;
  iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*piVar3);
  if (iVar5 != 0x390) {
    if (param_3 != 0) goto LAB_005fb9b0;
    iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"\n");
    uVar4 = (uint)(0 < iVar5);
    goto LAB_005fb9c8;
  }
  puVar6 = (undefined4 *)piVar3[1];
  if (puVar6 == (undefined4 *)0x0) {
LAB_005fbae8:
    iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2," (INVALID PSS PARAMETERS)\n");
    uVar4 = (uint)(0 < iVar5);
    if (uVar4 != 0) goto LAB_005fbad8;
    goto LAB_005fb9c8;
  }
  unaff_s5 = (undefined4 *)*puVar6;
  unaff_s6 = &uStack_70;
  if (unaff_s5 != (undefined4 *)&SUB_00000010) goto LAB_005fbae8;
  uStack_70 = ((undefined4 *)puVar6[1])[2];
  piVar3 = (int *)(*(code *)PTR_d2i_RSA_PSS_PARAMS_006aa834)(0,unaff_s6,*(undefined4 *)puVar6[1]);
  if (piVar3 == (int *)0x0) goto LAB_005fbae8;
  puVar6 = (undefined4 *)piVar3[1];
  if (puVar6 == (undefined4 *)0x0) {
LAB_005fba68:
    unaff_s5 = (undefined4 *)0x0;
  }
  else {
    piVar7 = (int *)puVar6[1];
    iVar5 = (*(code *)PTR_OBJ_obj2nid_006a822c)(*puVar6);
    if ((iVar5 != 0x38f) || (*piVar7 != 0x10)) goto LAB_005fba68;
    puVar6 = (undefined4 *)piVar7[1];
    uStack_70 = puVar6[2];
    unaff_s5 = (undefined4 *)(*(code *)PTR_d2i_X509_ALGOR_006a9ee4)(0,unaff_s6,*puVar6);
  }
  unaff_s6 = (undefined4 *)0x640000;
  iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"\n");
  if (((0 < iVar5) && (iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,param_4,0x80), iVar5 != 0))
     && (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"Hash Algorithm: "), 0 < iVar5)) {
    if ((undefined4 *)*piVar3 == (undefined4 *)0x0) {
      iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"sha1 (default)");
    }
    else {
      iVar5 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(iVar2,*(undefined4 *)*piVar3);
    }
    if (((0 < iVar5) && (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"\n"), 0 < iVar5)) &&
       ((iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,param_4,0x80), iVar5 != 0 &&
        (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"Mask Algorithm: "), 0 < iVar5)))) {
      if ((undefined4 *)piVar3[1] == (undefined4 *)0x0) {
        iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"mgf1 with sha1 (default)");
      }
      else {
        iVar5 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(iVar2,*(undefined4 *)piVar3[1]);
        if ((iVar5 < 1) || (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2," with "), iVar5 < 1))
        goto LAB_005fbaa8;
        if (unaff_s5 == (undefined4 *)0x0) goto LAB_005fbd9c;
        iVar5 = (*(code *)PTR_i2a_ASN1_OBJECT_006a812c)(iVar2,*unaff_s5);
      }
      if (0 < iVar5) goto LAB_005fbc10;
    }
  }
LAB_005fbaa8:
  (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(piVar3);
  uVar4 = 0;
  if (unaff_s5 == (undefined4 *)0x0) goto LAB_005fb9c8;
  do {
    (*(code *)PTR_X509_ALGOR_free_006a8f94)(unaff_s5);
    if (uVar4 == 0) goto LAB_005fb9c8;
LAB_005fbad8:
    do {
      uVar4 = 1;
      if (param_3 != 0) {
LAB_005fb9b0:
        uVar4 = (*(code *)PTR_X509_signature_dump_006aa830)(iVar2,param_3,param_4);
      }
LAB_005fb9c8:
      if (iStack_6c == *(int *)puVar1) {
        return uVar4;
      }
      (*(code *)PTR___stack_chk_fail_006aabb8)();
LAB_005fbd9c:
      iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"INVALID");
      if (iVar5 < 1) goto LAB_005fbaa8;
LAB_005fbc10:
      (*(code *)PTR_BIO_puts_006a8058)(iVar2,unaff_s6 + -0x114e);
      iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,param_4,0x80);
      if ((iVar5 == 0) ||
         (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"Salt Length: 0x"), iVar5 < 1))
      goto LAB_005fbaa8;
      if (piVar3[2] == 0) {
        iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"0x14 (default)");
      }
      else {
        iVar5 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar2);
      }
      if (iVar5 < 1) goto LAB_005fbaa8;
      (*(code *)PTR_BIO_puts_006a8058)(iVar2,unaff_s6 + -0x114e);
      iVar5 = (*(code *)PTR_BIO_indent_006a97d0)(iVar2,param_4,0x80);
      if ((iVar5 == 0) ||
         (iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"Trailer Field: 0x"), iVar5 < 1))
      goto LAB_005fbaa8;
      if (piVar3[3] == 0) {
        iVar5 = (*(code *)PTR_BIO_puts_006a8058)(iVar2,"BC (default)");
      }
      else {
        iVar5 = (*(code *)PTR_i2a_ASN1_INTEGER_006a86e4)(iVar2);
      }
      if (iVar5 < 1) goto LAB_005fbaa8;
      (*(code *)PTR_BIO_puts_006a8058)(iVar2,unaff_s6 + -0x114e);
      (*(code *)PTR_RSA_PSS_PARAMS_free_006aa824)(piVar3);
      uVar4 = 1;
    } while (unaff_s5 == (undefined4 *)0x0);
  } while( true );
}

