
int make_revocation_str(int param_1,int param_2)

{
  int iVar1;
  int *piVar2;
  int iVar3;
  char *pcVar4;
  
  if (param_1 == 2) {
    iVar1 = (*(code *)PTR_OBJ_txt2obj_006a8100)(param_2,0);
    (*(code *)PTR_ASN1_OBJECT_free_006a8104)(iVar1);
    if (iVar1 == 0) {
      pcVar4 = "Invalid object identifier %s\n";
LAB_0042f13c:
      (*(code *)PTR_BIO_printf_006a7f38)(*(undefined4 *)PTR_bio_err_006a7f3c,pcVar4,param_2);
      return 0;
    }
    pcVar4 = "holdInstruction";
LAB_0042f1d8:
    piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar1 = (*(code *)PTR_strlen_006aab30)(pcVar4);
    iVar1 = *piVar2 + 2 + iVar1;
    if (param_2 == 0) {
LAB_0042f3a4:
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,&DAT_00635b2c,0xae1);
      if (iVar3 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar3,piVar2[2],iVar1);
      if (pcVar4 == (char *)0x0) goto LAB_0042f2cc;
      param_2 = 0;
    }
    else {
      iVar3 = (*(code *)PTR_strlen_006aab30)(param_2);
      iVar1 = iVar1 + 1 + iVar3;
      iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1,&DAT_00635b2c,0xae1);
      if (iVar3 == 0) {
        return 0;
      }
      (*(code *)PTR_BUF_strlcpy_006a8064)(iVar3,piVar2[2],iVar1);
    }
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar3,",",iVar1);
    (*(code *)PTR_BUF_strlcat_006a8068)(iVar3,pcVar4,iVar1);
    if (param_2 != 0) {
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar3,",",iVar1);
      (*(code *)PTR_BUF_strlcat_006a8068)(iVar3,param_2,iVar1);
    }
  }
  else {
    if (param_1 < 3) {
      if (param_1 == 1) {
        iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"unspecified");
        if (iVar1 == 0) {
          pcVar4 = "unspecified";
        }
        else {
          iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"keyCompromise");
          if (iVar1 == 0) {
            pcVar4 = "keyCompromise";
          }
          else {
            iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"CACompromise");
            if (iVar1 == 0) {
              pcVar4 = "CACompromise";
            }
            else {
              iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"affiliationChanged");
              if (iVar1 == 0) {
                pcVar4 = "affiliationChanged";
              }
              else {
                iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"superseded");
                if (iVar1 == 0) {
                  pcVar4 = "superseded";
                }
                else {
                  iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"cessationOfOperation");
                  if (iVar1 == 0) {
                    pcVar4 = "cessationOfOperation";
                  }
                  else {
                    iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"certificateHold");
                    if (iVar1 == 0) {
                      pcVar4 = "certificateHold";
                    }
                    else {
                      iVar1 = (*(code *)PTR_strcasecmp_006aab24)(param_2,"removeFromCRL");
                      if (iVar1 != 0) {
                        pcVar4 = "Unknown CRL reason %s\n";
                        goto LAB_0042f13c;
                      }
                      pcVar4 = "removeFromCRL";
                    }
                  }
                }
              }
            }
          }
        }
        piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
        iVar1 = (*(code *)PTR_strlen_006aab30)(pcVar4);
        iVar1 = *piVar2 + 2 + iVar1;
        goto LAB_0042f3a4;
      }
    }
    else if (param_1 < 5) {
      iVar1 = (*(code *)PTR_ASN1_GENERALIZEDTIME_set_string_006a80fc)(0);
      if (iVar1 == 0) {
        pcVar4 = "Invalid time format %s. Need YYYYMMDDHHMMSSZ\n";
        goto LAB_0042f13c;
      }
      if (param_1 == 3) {
        pcVar4 = "keyTime";
      }
      else {
        pcVar4 = "CAkeyTime";
      }
      goto LAB_0042f1d8;
    }
    piVar2 = (int *)(*(code *)PTR_X509_gmtime_adj_006a808c)(0,0);
    iVar1 = *piVar2;
    iVar3 = (*(code *)PTR_CRYPTO_malloc_006a8108)(iVar1 + 1,&DAT_00635b2c,0xae1);
    if (iVar3 == 0) {
      return 0;
    }
    (*(code *)PTR_BUF_strlcpy_006a8064)(iVar3,piVar2[2],iVar1 + 1);
  }
LAB_0042f2cc:
  (*(code *)PTR_ASN1_UTCTIME_free_006a810c)(piVar2);
  return iVar3;
}

