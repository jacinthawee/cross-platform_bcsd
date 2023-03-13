
uint verify_callback(uint param_1,X509_STORE_CTX *param_2)

{
  X509 *a;
  int n;
  int iVar1;
  X509_NAME *pXVar2;
  char *pcVar3;
  ASN1_TIME *a_00;
  int iVar4;
  
  a = X509_STORE_CTX_get_current_cert(param_2);
  n = X509_STORE_CTX_get_error(param_2);
  iVar1 = X509_STORE_CTX_get_error_depth(param_2);
  iVar4 = iVar1;
  BIO_printf(bio_err,"depth=%d ",iVar1);
  if (a == (X509 *)0x0) {
    BIO_puts(bio_err,"<no cert>\n");
  }
  else {
    pXVar2 = X509_get_subject_name(a);
    X509_NAME_print_ex(bio_err,pXVar2,0,0x82031f);
    BIO_puts(bio_err,"\n");
  }
  if (param_1 == 0) {
    pcVar3 = X509_verify_cert_error_string(n);
    BIO_printf(bio_err,"verify error:num=%d:%s\n",n,pcVar3);
    if (verify_depth < iVar1) {
      verify_error = 0x16;
    }
    else {
      verify_error = 0;
      param_1 = (uint)(verify_return_error == 0);
    }
    switch(n) {
    default:
      goto switchD_0807e15d_caseD_0;
    case 2:
      goto switchD_0807e15d_caseD_2;
    case 9:
    case 0xd:
      goto switchD_0807e15d_caseD_9;
    case 10:
    case 0xe:
      goto switchD_0807e15d_caseD_a;
    case 0x2b:
      goto switchD_0807e15d_caseD_2b;
    }
  }
  switch(n) {
  case 2:
    goto switchD_0807e15d_caseD_2;
  case 9:
  case 0xd:
switchD_0807e15d_caseD_9:
    BIO_printf(bio_err,"notBefore=",iVar4);
    a_00 = a->cert_info->validity->notBefore;
    goto LAB_0807e036;
  case 10:
  case 0xe:
switchD_0807e15d_caseD_a:
    BIO_printf(bio_err,"notAfter=",iVar4);
    a_00 = a->cert_info->validity->notAfter;
LAB_0807e036:
    ASN1_TIME_print(bio_err,a_00);
    BIO_printf(bio_err,"\n");
    break;
  case 0x2b:
switchD_0807e15d_caseD_2b:
    policies_print(bio_err,param_2);
  }
switchD_0807e00b_caseD_0:
  if ((n == 0) && (param_1 == 2)) {
    policies_print(bio_err,param_2);
  }
switchD_0807e15d_caseD_0:
  BIO_printf(bio_err,"verify return:%d\n",param_1);
  return param_1;
switchD_0807e15d_caseD_2:
  BIO_puts(bio_err,"issuer= ");
  pXVar2 = X509_get_issuer_name(a);
  X509_NAME_print_ex(bio_err,pXVar2,0,0x82031f);
  BIO_puts(bio_err,"\n");
  goto switchD_0807e00b_caseD_0;
}

