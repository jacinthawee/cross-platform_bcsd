
char * SSL_state_string(SSL *s)

{
  int iVar1;
  
  iVar1 = s->state;
  if (iVar1 == 0x1221) {
    return "23RSHA";
  }
  if (iVar1 < 0x1222) {
    if (iVar1 == 0x1170) {
      return "3WCC_A";
    }
    if (iVar1 < 0x1171) {
      if (iVar1 == 0x1126) {
        return "DRCHVA";
      }
      if (iVar1 < 0x1127) {
        if (iVar1 == 0x1100) {
          return "3FLUSH";
        }
        if (iVar1 < 0x1101) {
          if (iVar1 == 5) {
            return "SSLERR";
          }
          if (iVar1 == 0x1000) {
            return "CINIT ";
          }
          if (iVar1 == 3) {
            return "SSLOK ";
          }
        }
        else {
          if (iVar1 == 0x1111) {
            return "3WCH_B";
          }
          if (iVar1 < 0x1112) {
            if (iVar1 == 0x1110) {
              return "3WCH_A";
            }
          }
          else {
            if (iVar1 == 0x1120) {
              return "3RSH_A";
            }
            if (iVar1 == 0x1121) {
              return "3RSH_B";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x1141) {
          return "3RSKEB";
        }
        if (iVar1 < 0x1142) {
          if (iVar1 == 0x1130) {
            return "3RSC_A";
          }
          if (iVar1 < 0x1131) {
            if (iVar1 == 0x1127) {
              return "DRCHVB";
            }
          }
          else {
            if (iVar1 == 0x1131) {
              return "3RSC_B";
            }
            if (iVar1 == 0x1140) {
              return "3RSKEA";
            }
          }
        }
        else {
          if (iVar1 == 0x1151) {
            return "3RCR_B";
          }
          if (iVar1 < 0x1152) {
            if (iVar1 == 0x1150) {
              return "3RCR_A";
            }
          }
          else {
            if (iVar1 == 0x1160) {
              return "3RSD_A";
            }
            if (iVar1 == 0x1161) {
              return "3RSD_B";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x11a1) {
        return "3WCCSB";
      }
      if (iVar1 < 0x11a2) {
        if (iVar1 == 0x1180) {
          return "3WCKEA";
        }
        if (iVar1 < 0x1181) {
          if (iVar1 == 0x1172) {
            return "3WCC_C";
          }
          if (iVar1 < 0x1172) {
            return "3WCC_B";
          }
          if (iVar1 == 0x1173) {
            return "3WCC_D";
          }
        }
        else {
          if (iVar1 == 0x1190) {
            return "3WCV_A";
          }
          if (iVar1 < 0x1191) {
            if (iVar1 == 0x1181) {
              return "3WCKEB";
            }
          }
          else {
            if (iVar1 == 0x1191) {
              return "3WCV_B";
            }
            if (iVar1 == 0x11a0) {
              return "3WCCSA";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x11d0) {
          return "3RFINA";
        }
        if (iVar1 < 0x11d1) {
          if (iVar1 == 0x11b1) {
            return "3WFINB";
          }
          if (iVar1 < 0x11b2) {
            if (iVar1 == 0x11b0) {
              return "3WFINA";
            }
          }
          else {
            if (iVar1 == 0x11c0) {
              return "3RCCSA";
            }
            if (iVar1 == 0x11c1) {
              return "3RCCSB";
            }
          }
        }
        else {
          if (iVar1 == 0x1210) {
            return "23WCHA";
          }
          if (iVar1 < 0x1211) {
            if (iVar1 == 0x11d1) {
              return "3RFINB";
            }
          }
          else {
            if (iVar1 == 0x1211) {
              return "23WCHB";
            }
            if (iVar1 == 0x1220) {
              return "23RSHA";
            }
          }
        }
      }
    }
  }
  else {
    if (iVar1 == 0x2170) {
      return "3WSD_A";
    }
    if (iVar1 < 0x2171) {
      if (iVar1 == 0x2121) {
        return "3WHR_B";
      }
      if (iVar1 < 0x2122) {
        if (iVar1 == 0x2111) {
          return "3RCH_B";
        }
        if (iVar1 < 0x2112) {
          if (iVar1 == 0x2100) {
            return "3FLUSH";
          }
          if (iVar1 == 0x2110) {
            return "3RCH_A";
          }
          if (iVar1 == 0x2000) {
            return "AINIT ";
          }
        }
        else {
          if (iVar1 == 0x2113) {
            return "DWCHVA";
          }
          if (iVar1 < 0x2113) {
            return "3RCH_C";
          }
          if (iVar1 == 0x2114) {
            return "DWCHVB";
          }
          if (iVar1 == 0x2120) {
            return "3WHR_A";
          }
        }
      }
      else {
        if (iVar1 == 0x2141) {
          return "3WSC_B";
        }
        if (iVar1 < 0x2142) {
          if (iVar1 == 0x2130) {
            return "3WSH_A";
          }
          if (iVar1 < 0x2131) {
            if (iVar1 == 0x2122) {
              return "3WHR_C";
            }
          }
          else {
            if (iVar1 == 0x2131) {
              return "3WSH_B";
            }
            if (iVar1 == 0x2140) {
              return "3WSC_A";
            }
          }
        }
        else {
          if (iVar1 == 0x2151) {
            return "3WSKEB";
          }
          if (iVar1 < 0x2152) {
            if (iVar1 == 0x2150) {
              return "3WSKEA";
            }
          }
          else {
            if (iVar1 == 0x2160) {
              return "3WCR_A";
            }
            if (iVar1 == 0x2161) {
              return "3WCR_B";
            }
          }
        }
      }
    }
    else {
      if (iVar1 == 0x21b1) {
        return "3RCCSB";
      }
      if (iVar1 < 0x21b2) {
        if (iVar1 == 0x2190) {
          return "3RCKEA";
        }
        if (iVar1 < 0x2191) {
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
        else {
          if (iVar1 == 0x21a0) {
            return "3RCV_A";
          }
          if (iVar1 < 0x21a1) {
            if (iVar1 == 0x2191) {
              return "3RCKEB";
            }
          }
          else {
            if (iVar1 == 0x21a1) {
              return "3RCV_B";
            }
            if (iVar1 == 0x21b0) {
              return "3RCCSA";
            }
          }
        }
      }
      else {
        if (iVar1 == 0x21e0) {
          return "3WFINA";
        }
        if (iVar1 < 0x21e1) {
          if (iVar1 == 0x21c1) {
            return "3RFINB";
          }
          if (iVar1 < 0x21c2) {
            if (iVar1 == 0x21c0) {
              return "3RFINA";
            }
          }
          else {
            if (iVar1 == 0x21d0) {
              return "3WCCSA";
            }
            if (iVar1 == 0x21d1) {
              return "3WCCSB";
            }
          }
        }
        else {
          if (iVar1 == 0x2210) {
            return "23RCHA";
          }
          if (iVar1 < 0x2211) {
            if (iVar1 == 0x21e1) {
              return "3WFINB";
            }
          }
          else {
            if (iVar1 == 0x2211) {
              return "23RCHB";
            }
            if (iVar1 == 0x4000) {
              return "PINIT ";
            }
          }
        }
      }
    }
  }
  return "UNKWN ";
}

