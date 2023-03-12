
int DES_is_weak_key(const_DES_cblock *key)

{
  int iVar1;
  
  iVar1 = (*(code *)PTR_memcmp_006aabd8)(weak_keys,key,8);
  if (iVar1 != 0) {
    iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8b8,key,8);
    if (iVar1 != 0) {
      iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8c0,key,8);
      if (iVar1 != 0) {
        iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8c8,key,8);
        if (iVar1 != 0) {
          iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8d0,key,8);
          if (iVar1 != 0) {
            iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8d8,key,8);
            if (iVar1 != 0) {
              iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8e0,key,8);
              if (iVar1 != 0) {
                iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8e8,key,8);
                if (iVar1 != 0) {
                  iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8f0,key,8);
                  if (iVar1 != 0) {
                    iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b8f8,key,8);
                    if (iVar1 != 0) {
                      iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b900,key,8);
                      if (iVar1 != 0) {
                        iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b908,key,8);
                        if (iVar1 != 0) {
                          iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b910,key,8);
                          if (iVar1 != 0) {
                            iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b918,key,8);
                            if (iVar1 != 0) {
                              iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b920,key,8);
                              if (iVar1 != 0) {
                                iVar1 = (*(code *)PTR_memcmp_006aabd8)(0x65b928,key,8);
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

