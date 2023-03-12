
int make_revocation_str(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_1 == 2) {
    iVar1 = (*(code *)PTR_OBJ_txt2obj_006a7000)(param_2,0);
    (*(code *)PTR_ASN1_OBJECT_free_006a7004)(iVar1);
    if (iVar1 == 0) {
      pcVar4 = "Invalid object identifier %s\n";
LAB_0042f24c:
      (*(code *)PTR_BIO_printf_006a6e38)(*(undefined4 *)PTR_bio_err_006a6e3c,pcVar4,param_2);
      return 0;
    }
    pcVar4 = "holdInstruction";
LAB_0042f2e8:
    piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
    if (piVar2 == (int *)0x0) {
      return 0;
    }
    iVar1 = (*(code *)PTR_strlen_006a9a24)(pcVar4);
    iVar1 = *piVar2 + 2 + iVar1;
    if (param_2 == 0) {
LAB_0042f4c0:
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,&DAT_0063526c,0xa6e);
      if (iVar3 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a6f64)(iVar3,piVar2[2],iVar1);
      if (pcVar4 == (char *)0x0) goto LAB_0042f3e0;
      param_2 = 0;
    }
    else {
      iVar3 = (*(code *)PTR_strlen_006a9a24)(param_2);
      iVar1 = iVar1 + 1 + iVar3;
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1,&DAT_0063526c,0xa6e);
      if (iVar3 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a6f64)(iVar3,piVar2[2],iVar1);
    }
    (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,",",iVar1);
    (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,pcVar4,iVar1);
    if (param_2 != 0) {
      (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,",",iVar1);
      (*(code *)PTR_BUF_strlcat_006a6f68)(iVar3,param_2,iVar1);
    }
LAB_0042f3e0:
    (*(code *)PTR_ASN1_UTCTIME_free_006a700c)(piVar2);
    return iVar3;
  }
  if (param_1 < 3) {
    if (param_1 == 1) {
      iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"unspecified");
      if (iVar1 == 0) {
        pcVar4 = "unspecified";
      }
      else {
        iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"keyCompromise");
        if (iVar1 == 0) {
          pcVar4 = "keyCompromise";
        }
        else {
          iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"CACompromise");
          if (iVar1 == 0) {
            pcVar4 = "CACompromise";
          }
          else {
            iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"affiliationChanged");
            if (iVar1 == 0) {
              pcVar4 = "affiliationChanged";
            }
            else {
              iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"superseded");
              if (iVar1 == 0) {
                pcVar4 = "superseded";
              }
              else {
                iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"cessationOfOperation");
                if (iVar1 == 0) {
                  pcVar4 = "cessationOfOperation";
                }
                else {
                  iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"certificateHold");
                  if (iVar1 == 0) {
                    pcVar4 = "certificateHold";
                  }
                  else {
                    iVar1 = (*(code *)PTR_strcasecmp_006a9a18)(param_2,"removeFromCRL");
                    if (iVar1 != 0) {
                      pcVar4 = "Unknown CRL reason %s\n";
                      goto LAB_0042f24c;
                    }
                    pcVar4 = "removeFromCRL";
                  }
                }
              }
            }
          }
        }
      }
      piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
      if (piVar2 == (int *)0x0) {
        return 0;
      }
      iVar1 = (*(code *)PTR_strlen_006a9a24)(pcVar4);
      iVar1 = *piVar2 + 2 + iVar1;
      goto LAB_0042f4c0;
    }
  }
  else if (param_1 < 5) {
    iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a6ffc)(0);
    if (iVar1 == 0) {
      pcVar4 = "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n";
      goto LAB_0042f24c;
    }
    if (param_1 == 3) {
      pcVar4 = "keyTime";
    }
    else {
      pcVar4 = "CAkeyTime";
    }
    goto LAB_0042f2e8;
  }
  piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a6f8c)(0,0);
  if (piVar2 != (int *)0x0) {
    iVar1 = *piVar2;
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a7008)(iVar1 + 1,&DAT_0063526c,0xa6e);
    if (iVar3 != 0) {
      (*(code *)PTR_BUF_strlcpy_006a6f64)(iVar3,piVar2[2],iVar1 + 1);
      goto LAB_0042f3e0;
    }
  }
  return 0;
}

