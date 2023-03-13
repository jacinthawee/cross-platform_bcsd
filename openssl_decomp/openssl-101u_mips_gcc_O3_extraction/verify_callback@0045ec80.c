
uint verify_callback(uint param_1,undefined4 param_2)

{
  undefined *puVar1;
  int *piVar2;
  int iVar3;
  int iVar4;
  undefined4 uVar5;
  undefined4 uVar6;
  
  puVar1 = PTR_bio_err_006a6e3c;
  piVar2 = (int *)(*(code *)PTR_X509_STORE_CTX_get_current_cert_006a744c)(param_2);
  iVar3 = (*(code *)PTR_X509_STORE_CTX_get_error_006a729c)(param_2);
  iVar4 = (*(code *)PTR_X509_STORE_CTX_get_error_depth_006a7458)(param_2);
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"depth=%d ",iVar4);
  if (piVar2 == (int *)0x0) {
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar1,"<no cert>\n");
  }
  else {
    uVar6 = *(undefined4 *)puVar1;
    uVar5 = (*(code *)PTR_X509_get_subject_name_006a6f00)(piVar2);
    (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(uVar6,uVar5,0,0x82031f);
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar1,"\n");
  }
  if (param_1 == 0) {
    uVar6 = *(undefined4 *)puVar1;
    uVar5 = (*(code *)PTR_X509_verify_cert_error_string_006a72a0)(iVar3);
    (*(code *)PTR_BIO_printf_006a6e38)(uVar6,"verify error:num=%d:%s\n",iVar3,uVar5);
    if (verify_depth < iVar4) {
      verify_error = 0x16;
    }
    else {
      verify_error = 0;
      param_1 = (uint)(verify_return_error == 0);
    }
  }
  switch(iVar3) {
  default:
    if ((iVar3 != 0) || (param_1 != 2)) break;
  case 0x2b:
    policies_print(*(undefined4 *)puVar1,param_2);
    break;
  case 2:
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar1,"issuer= ");
    uVar6 = *(undefined4 *)puVar1;
    uVar5 = (*(code *)PTR_X509_get_issuer_name_006a76e4)(piVar2);
    (*(code *)PTR_X509_NAME_print_ex_006a7bc4)(uVar6,uVar5,0,0x82031f);
    (*(code *)PTR_BIO_puts_006a6f58)(*(undefined4 *)puVar1,"\n");
    break;
  case 9:
  case 0xd:
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"notBefore=");
    uVar5 = *(undefined4 *)puVar1;
    uVar6 = **(undefined4 **)(*piVar2 + 0x10);
    goto LAB_0045ee24;
  case 10:
  case 0xe:
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"notAfter=");
    uVar5 = *(undefined4 *)puVar1;
    uVar6 = *(undefined4 *)(*(int *)(*piVar2 + 0x10) + 4);
LAB_0045ee24:
    (*(code *)PTR_ASN1_TIME_print_006a716c)(uVar5,uVar6);
    (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"\n");
  }
  (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)puVar1,"verify return:%d\n",param_1);
  return param_1;
}

