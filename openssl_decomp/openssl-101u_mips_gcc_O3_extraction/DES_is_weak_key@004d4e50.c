
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(weak_keys,key,8);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65aef8,key,8);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af00,key,8);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af08,key,8);
        if (iVar1 != 0) {
          iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af10,key,8);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af18,key,8);
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af20,key,8);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af28,key,8);
                if (iVar1 != 0) {
                  iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af30,key,8);
                  if (iVar1 != 0) {
                    iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af38,key,8);
                    if (iVar1 != 0) {
                      iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af40,key,8);
                      if (iVar1 != 0) {
                        iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af48,key,8);
                        if (iVar1 != 0) {
                          iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af50,key,8);
                          if (iVar1 != 0) {
                            iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af58,key,8);
                            if (iVar1 != 0) {
                              iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af60,key,8);
                              if (iVar1 != 0) {
                                iVar1 = (*(code *)PTR_memcmp_006a9ad0)(0x65af68,key,8);
                                return (uint)(iVar1 == 0);
                              }
                            }
                          }
                        }
                      }
                    }
                  }
                }
              }
            }
          }
        }
      }
    }
  }
  return 1;
}

