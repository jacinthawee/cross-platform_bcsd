
uint verify_callback(uint param_1,X509_STORE_CTX *param_2)

{
  BIO *pBVar1;
  X509 *a;
  int n;
  int iVar2;
  X509_NAME *pXVar3;
  char *pcVar4;
  ASN1_TIME *a_00;
  
  a = X509_STORE_CTX_get_current_cert(param_2);
  n = X509_STORE_CTX_get_error(param_2);
  iVar2 = X509_STORE_CTX_get_error_depth(param_2);
  BIO_printf(bio_err,"depth=%d ",iVar2);
  pBVar1 = bio_err;
  if (a == (X509 *)0x0) {
    BIO_puts(bio_err,"<no cert>\n");
  }
  else {
    pXVar3 = X509_get_subject_name(a);
    X509_NAME_print_ex(pBVar1,pXVar3,0,0x82031f);
    BIO_puts(bio_err,"\n");
  }
  pBVar1 = bio_err;
  if (param_1 == 0) {
    pcVar4 = X509_verify_cert_error_string(n);
    BIO_printf(pBVar1,"verify error:num=%d:%s\n",n,pcVar4);
    if (verify_depth < iVar2) {
      verify_error = 0x16;
    }
    else {
      verify_error = 0;
      param_1 = count_leading_zeroes(verify_return_error);
      param_1 = param_1 >> 5;
    }
  }
  switch(n) {
  case 2:
    BIO_puts(bio_err,"issuer= ");
    pBVar1 = bio_err;
    pXVar3 = X509_get_issuer_name(a);
    X509_NAME_print_ex(pBVar1,pXVar3,0,0x82031f);
    BIO_puts(bio_err,"\n");
    goto LAB_000359f0;
  default:
    goto switchD_00035988_caseD_3;
  case 9:
  case 0xd:
    BIO_printf(bio_err,"notBefore=");
    a_00 = a->cert_info->validity->notBefore;
    break;
  case 10:
  case 0xe:
    BIO_printf(bio_err,"notAfter=");
    a_00 = a->cert_info->validity->notAfter;
    break;
  case 0x2b:
    goto switchD_00035988_caseD_2b;
  }
  ASN1_TIME_print(bio_err,a_00);
  BIO_printf(bio_err,"\n");
switchD_00035988_caseD_3:
  if (param_1 == 2 && n == 0) {
switchD_00035988_caseD_2b:
    policies_print(bio_err,param_2);
  }
LAB_000359f0:
  BIO_printf(bio_err,"verify return:%d\n",param_1);
  return param_1;
}

