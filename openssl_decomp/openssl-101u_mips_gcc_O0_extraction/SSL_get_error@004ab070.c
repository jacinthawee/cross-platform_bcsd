
/* WARNING: Type propagation algorithm not settling */

int SSL_get_error(SSL *s,int ret_code)

{
  uint uVar1;
  int iVar2;
  BIO *pBVar3;
  
  if (0 < ret_code) {
    return 0;
  }
  uVar1 = (*(code *)PTR_ERR_peek_error_006a6f54)();
  if (uVar1 != 0) {
    if (uVar1 >> 0x18 != 2) {
      return 1;
    }
    return 5;
  }
  if (ret_code == 0) {
    if (s->version != 2) {
      if ((s->shutdown & 2U) == 0) {
        return 5;
      }
      if (s->s3->warn_alert != 0) {
        return 5;
      }
    }
    return 6;
  }
  iVar2 = s->rwstate;
  if (iVar2 == 3) {
    pBVar3 = s->rbio;
    iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,1);
    if (iVar2 != 0) {
      return 2;
    }
    iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,2);
    if (iVar2 == 0) {
      iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,4);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_BIO_get_retry_reason_006a786c)(pBVar3);
        goto joined_r0x004ab0f0;
      }
      iVar2 = s->rwstate;
      goto LAB_004ab16c;
    }
LAB_004ab1c4:
    iVar2 = 3;
  }
  else {
LAB_004ab16c:
    if (iVar2 == 2) {
      pBVar3 = s->wbio;
      iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,2);
      if (iVar2 != 0) goto LAB_004ab1c4;
      iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,1);
      if (iVar2 != 0) {
        return 2;
      }
      iVar2 = (*(code *)PTR_BIO_test_flags_006a7868)(pBVar3,4);
      if (iVar2 != 0) {
        iVar2 = (*(code *)PTR_BIO_get_retry_reason_006a786c)(pBVar3);
joined_r0x004ab0f0:
        if (iVar2 == 2) {
          return 7;
        }
        if (iVar2 == 3) {
          return 8;
        }
        return 5;
      }
      iVar2 = s->rwstate;
    }
    if (iVar2 != 4) {
      return 5;
    }
  }
  return iVar2;
}

