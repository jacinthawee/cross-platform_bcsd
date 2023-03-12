
char * SSL_state_string(SSL *s)

{
  int iVar1;
  char *pcVar2;
  
  iVar1 = s->state;
  if (iVar1 == 0x2000) {
    return "AINIT ";
  }
  if (iVar1 < 0x2001) {
    if (iVar1 == 0x1130) {
      return "3RSC_A";
    }
    if (iVar1 < 0x1131) {
      if (iVar1 == 0x1053) {
        return "2SCC_D";
      }
      if (iVar1 < 0x1054) {
        if (iVar1 == 0x1030) {
          return "2SCMKA";
        }
        if (iVar1 < 0x1031) {
          if (iVar1 == 0x1010) {
            return "2SCH_A";
          }
          if (iVar1 < 0x1011) {
            if (iVar1 == 3) {
              return "SSLOK ";
            }
            if (iVar1 == 0x1000) {
              return "CINIT ";
            }
          }
          else {
            if (iVar1 == 0x1020) {
              return "2GSH_A";
            }
            if (iVar1 == 0x1021) {
              return "2GSH_B";
            }
            if (iVar1 == 0x1011) {
              return "2SCH_B";
            }
          }
        }
        else {
          if (iVar1 == 0x1041) {
            return "2SCF_B";
          }
          if (iVar1 < 0x1042) {
            if (iVar1 == 0x1031) {
              return "2SCMKB";
            }
            if (iVar1 == 0x1040) {
              return "2SCF_A";
            }
          }
          else {
            if (iVar1 == 0x1051) {
              return "2SCC_B";
            }
            if (0x1051 < iVar1) {
              return "2SCC_C";
            }
            if (iVar1 == 0x1050) {
              return "2SCC_A";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x1100) goto LAB_080caff1;
        if (iVar1 < 0x1101) {
          if (iVar1 == 0x1070) {
            return "2GSF_A";
          }
          if (iVar1 < 0x1071) {
            if (iVar1 == 0x1060) {
              return "2GSV_A";
            }
            if (iVar1 == 0x1061) {
              return "2GSV_B";
            }
          }
          else {
            if (iVar1 == 0x1080) {
              return "2CSENC";
            }
            if (iVar1 == 0x1090) {
              return "2X9GCC";
            }
            if (iVar1 == 0x1071) {
              return "2GSF_B";
            }
          }
        }
        else {
          if (iVar1 == 0x1120) {
            return "3RSH_A";
          }
          if (iVar1 < 0x1121) {
            if (iVar1 == 0x1110) {
              return "3WCH_A";
            }
            if (iVar1 == 0x1111) {
              return "3WCH_B";
            }
          }
          else {
            if (iVar1 == 0x1126) {
              return "DRCHVA";
            }
            if (iVar1 == 0x1127) {
              return "DRCHVB";
            }
            if (iVar1 == 0x1121) {
              return "3RSH_B";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x1190) {
        return "3WCV_A";
      }
      if (iVar1 < 0x1191) {
        if (iVar1 == 0x1161) {
          return "3RSD_B";
        }
        if (iVar1 < 0x1162) {
          if (iVar1 == 0x1141) {
            return "3RSKEB";
          }
          if (iVar1 < 0x1142) {
            if (iVar1 == 0x1131) {
              return "3RSC_B";
            }
            if (iVar1 == 0x1140) {
              return "3RSKEA";
            }
          }
          else {
            if (iVar1 == 0x1151) {
              return "3RCR_B";
            }
            if (iVar1 == 0x1160) {
              return "3RSD_A";
            }
            if (iVar1 == 0x1150) {
              return "3RCR_A";
            }
          }
        }
        else {
          if (iVar1 == 0x1172) {
            return "3WCC_C";
          }
          if (iVar1 < 0x1173) {
            if (iVar1 == 0x1170) {
              return "3WCC_A";
            }
            if (iVar1 == 0x1171) {
              return "3WCC_B";
            }
          }
          else {
            if (iVar1 == 0x1180) {
              return "3WCKEA";
            }
            if (iVar1 == 0x1181) {
              return "3WCKEB";
            }
            if (iVar1 == 0x1173) {
              return "3WCC_D";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x11c1) {
LAB_080caff7:
          return "3RCCSB";
        }
        if (iVar1 < 0x11c2) {
          if (iVar1 == 0x11a1) {
LAB_080cafe5:
            return "3WCCSB";
          }
          if (iVar1 < 0x11a2) {
            if (iVar1 == 0x1191) {
              return "3WCV_B";
            }
            if (iVar1 == 0x11a0) {
LAB_080cad0f:
              return "3WCCSA";
            }
          }
          else {
            if (iVar1 == 0x11b1) goto LAB_080cafd3;
            if (iVar1 == 0x11c0) goto LAB_080caf8c;
            if (iVar1 == 0x11b0) goto LAB_080caf68;
          }
        }
        else {
          if (iVar1 == 0x1210) {
            return "23WCHA";
          }
          if (iVar1 < 0x1211) {
            if (iVar1 == 0x11d0) {
LAB_080cafdf:
              return "3RFINA";
            }
            if (iVar1 == 0x11d1) goto LAB_080cafcd;
          }
          else {
            if (iVar1 == 0x1220) {
              return "23RSHA";
            }
            if (iVar1 == 0x1221) {
              return "23RSHA";
            }
            if (iVar1 == 0x1211) {
              return "23WCHB";
            }
          }
        }
      }
    }
  }
  else {
    if (iVar1 == 0x2121) {
      return "3WHR_B";
    }
    if (iVar1 < 0x2122) {
      if (iVar1 == 0x2061) {
        return "2SSF_B";
      }
      if (iVar1 < 0x2062) {
        if (iVar1 == 0x2031) {
          return "2GCMKA";
        }
        if (iVar1 < 0x2032) {
          if (iVar1 == 0x2012) {
            return "2GCH_C";
          }
          if (iVar1 < 0x2013) {
            if (iVar1 == 0x2010) {
              return "2GCH_A";
            }
            if (iVar1 == 0x2011) {
              return "2GCH_B";
            }
          }
          else {
            pcVar2 = "2SSH_B";
            if ((iVar1 == 0x2021) || (pcVar2 = "2GCMKA", iVar1 == 0x2030)) {
              return pcVar2;
            }
            if (iVar1 == 0x2020) {
              return "2SSH_A";
            }
          }
        }
        else {
          if (iVar1 == 0x2042) {
            return "2SSV_C";
          }
          if (iVar1 < 0x2043) {
            if (iVar1 == 0x2040) {
              return "2SSV_A";
            }
            if (iVar1 == 0x2041) {
              return "2SSV_B";
            }
          }
          else {
            if (iVar1 == 0x2051) {
              return "2GCF_B";
            }
            if (iVar1 == 0x2060) {
              return "2SSF_A";
            }
            if (iVar1 == 0x2050) {
              return "2GCF_A";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x2100) {
LAB_080caff1:
          return "3FLUSH";
        }
        if (iVar1 < 0x2101) {
          if (iVar1 == 0x2072) {
            return "2SRC_C";
          }
          if (iVar1 < 0x2073) {
            if (iVar1 == 0x2070) {
              return "2SRC_A";
            }
            if (iVar1 == 0x2071) {
              return "2SRC_B";
            }
          }
          else {
            if (iVar1 == 0x2080) {
              return "2SSENC";
            }
            if (iVar1 == 0x2090) {
              return "2X9GSC";
            }
            if (iVar1 == 0x2073) {
              return "2SRC_D";
            }
          }
        }
        else {
          if (iVar1 == 0x2112) {
            return "3RCH_C";
          }
          if (iVar1 < 0x2113) {
            if (iVar1 == 0x2110) {
              return "3RCH_A";
            }
            if (iVar1 == 0x2111) {
              return "3RCH_B";
            }
          }
          else {
            if (iVar1 == 0x2114) {
              return "DWCHVB";
            }
            if (iVar1 < 0x2114) {
              return "DWCHVA";
            }
            if (iVar1 == 0x2120) {
              return "3WHR_A";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x2190) {
        return "3RCKEA";
      }
      if (iVar1 < 0x2191) {
        if (iVar1 == 0x2151) {
          return "3WSKEB";
        }
        if (iVar1 < 0x2152) {
          if (iVar1 == 0x2131) {
            return "3WSH_B";
          }
          if (iVar1 < 0x2132) {
            if (iVar1 == 0x2122) {
              return "3WHR_C";
            }
            if (iVar1 == 0x2130) {
              return "3WSH_A";
            }
          }
          else {
            if (iVar1 == 0x2141) {
              return "3WSC_B";
            }
            if (iVar1 == 0x2150) {
              return "3WSKEA";
            }
            if (iVar1 == 0x2140) {
              return "3WSC_A";
            }
          }
        }
        else {
          if (iVar1 == 0x2170) {
            return "3WSD_A";
          }
          if (iVar1 < 0x2171) {
            if (iVar1 == 0x2160) {
              return "3WCR_A";
            }
            if (iVar1 == 0x2161) {
              return "3WCR_B";
            }
          }
          else {
            if (iVar1 == 0x2180) {
              return "3RCC_A";
            }
            if (iVar1 == 0x2181) {
              return "3RCC_B";
            }
            if (iVar1 == 0x2171) {
              return "3WSD_B";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x21c1) {
LAB_080cafcd:
          return "3RFINB";
        }
        if (iVar1 < 0x21c2) {
          if (iVar1 == 0x21a1) {
            return "3RCV_B";
          }
          if (iVar1 < 0x21a2) {
            if (iVar1 == 0x2191) {
              return "3RCKEB";
            }
            if (iVar1 == 0x21a0) {
              return "3RCV_A";
            }
          }
          else {
            if (iVar1 == 0x21b1) goto LAB_080caff7;
            if (iVar1 == 0x21c0) goto LAB_080cafdf;
            if (iVar1 == 0x21b0) {
LAB_080caf8c:
              return "3RCCSA";
            }
          }
        }
        else {
          if (iVar1 == 0x21e1) {
LAB_080cafd3:
            return "3WFINB";
          }
          if (iVar1 < 0x21e2) {
            if (iVar1 == 0x21d1) goto LAB_080cafe5;
            if (iVar1 == 0x21e0) {
LAB_080caf68:
              return "3WFINA";
            }
            if (iVar1 == 0x21d0) goto LAB_080cad0f;
          }
          else {
            if (iVar1 == 0x2211) {
              return "23RCHB";
            }
            if (iVar1 == 0x4000) {
              return "PINIT ";
            }
            if (iVar1 == 0x2210) {
              return "23RCHA";
            }
          }
        }
      }
    }
  }
  return "UNKWN ";
}

