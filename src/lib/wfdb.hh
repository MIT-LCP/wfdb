/* file: wfdb.hh		G. Moody	13 June 1983

WFDB library type, constant, structure, and function interface definitions

*/
#ifndef WFDB_LIB_WFDB_H_
#define WFDB_LIB_WFDB_H_

#include <string>

#ifndef WFDB_BUILD_DATE
#define WFDB_BUILD_DATE __DATE__
#endif

/* WFDB library version. */
constexpr char WFDB_MAJOR[] = "20";
constexpr char WFDB_MINOR[] = "0";
constexpr char WFDB_RELEASE[] = "0";
constexpr int WFDB_NETFILES =
    1; /* if 1, library includes code for HTTP, FTP clients */

/* Simple data types */
typedef int WFDB_Sample;             /* units are adus */
typedef long WFDB_Date;              /* units are days */
typedef double WFDB_Frequency;       /* units are Hz (samples/second/signal) */
typedef double WFDB_Gain;            /* units are adus per physical unit */
typedef unsigned int WFDB_Group;     /* signal group number */
typedef unsigned int WFDB_Signal;    /* signal number */
typedef unsigned int WFDB_Annotator; /* annotator number */

/* The following macros can be used to determine the ranges of the
   above data types.  You will also need to include <limits.h> and/or
   <float.h>. */
#define WFDB_SAMPLE_MIN INT_MIN
#define WFDB_SAMPLE_MAX INT_MAX
#define WFDB_DATE_MIN LONG_MIN
#define WFDB_DATE_MAX LONG_MAX
#define WFDB_FREQUENCY_MAX DBL_MAX
#define WFDB_FREQUENCY_DIG DBL_DIG
#define WFDB_FREQUENCY_MAX_10_EXP DBL_MAX_10_EXP
#define WFDB_FREQUENCY_EPSILON DBL_EPSILON
#define WFDB_GAIN_MAX DBL_MAX
#define WFDB_GAIN_DIG DBL_DIG
#define WFDB_GAIN_MAX_10_EXP DBL_MAX_10_EXP
#define WFDB_GAIN_EPSILON DBL_EPSILON
#define WFDB_GROUP_MAX UINT_MAX
#define WFDB_SIGNAL_MAX UINT_MAX
#define WFDB_ANNOTATOR_MAX UINT_MAX

/* The 'WFDB_Time' type is traditionally defined as a long integer.
   However, if the preprocessor symbol WFDB_LARGETIME is defined prior
   to including this file, it is defined as a 'long long' instead. */
typedef long long WFDB_Time;
#define WFDB_TIME_MIN LLONG_MIN
#define WFDB_TIME_MAX LLONG_MAX
#define WFDB_TIME_PRINTF_MODIFIER "ll"
#define WFDB_TIME_SCANF_MODIFIER "ll"

/* The following macros can be used to construct format strings for
   printf and scanf, and related standard library functions. */

#define WFDB_SAMPLE_PRINTF_MODIFIER ""
#define WFDB_SAMPLE_SCANF_MODIFIER ""
#define WFDB_FREQUENCY_PRINTF_MODIFIER ""
#define WFDB_FREQUENCY_SCANF_MODIFIER "l"
#define WFDB_GAIN_PRINTF_MODIFIER ""
#define WFDB_GAIN_SCANF_MODIFIER "l"

#define WFDB_Pd_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "d"
#define WFDB_Pi_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "i"
#define WFDB_Po_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "o"
#define WFDB_Pu_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "u"
#define WFDB_Px_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "x"
#define WFDB_PX_SAMP WFDB_SAMPLE_PRINTF_MODIFIER "X"
#define WFDB_Sd_SAMP WFDB_SAMPLE_SCANF_MODIFIER "d"
#define WFDB_Si_SAMP WFDB_SAMPLE_SCANF_MODIFIER "i"
#define WFDB_So_SAMP WFDB_SAMPLE_SCANF_MODIFIER "o"
#define WFDB_Su_SAMP WFDB_SAMPLE_SCANF_MODIFIER "u"
#define WFDB_Sx_SAMP WFDB_SAMPLE_SCANF_MODIFIER "x"
#define WFDB_SX_SAMP WFDB_SAMPLE_SCANF_MODIFIER "X"
#define WFDB_Pd_TIME WFDB_TIME_PRINTF_MODIFIER "d"
#define WFDB_Pi_TIME WFDB_TIME_PRINTF_MODIFIER "i"
#define WFDB_Po_TIME WFDB_TIME_PRINTF_MODIFIER "o"
#define WFDB_Pu_TIME WFDB_TIME_PRINTF_MODIFIER "u"
#define WFDB_Px_TIME WFDB_TIME_PRINTF_MODIFIER "x"
#define WFDB_PX_TIME WFDB_TIME_PRINTF_MODIFIER "X"
#define WFDB_Sd_TIME WFDB_TIME_SCANF_MODIFIER "d"
#define WFDB_Si_TIME WFDB_TIME_SCANF_MODIFIER "i"
#define WFDB_So_TIME WFDB_TIME_SCANF_MODIFIER "o"
#define WFDB_Su_TIME WFDB_TIME_SCANF_MODIFIER "u"
#define WFDB_Sx_TIME WFDB_TIME_SCANF_MODIFIER "x"
#define WFDB_SX_TIME WFDB_TIME_SCANF_MODIFIER "X"
#define WFDB_Pe_FREQ WFDB_FREQUENCY_PRINTF_MODIFIER "e"
#define WFDB_PE_FREQ WFDB_FREQUENCY_PRINTF_MODIFIER "E"
#define WFDB_Pf_FREQ WFDB_FREQUENCY_PRINTF_MODIFIER "f"
#define WFDB_Pg_FREQ WFDB_FREQUENCY_PRINTF_MODIFIER "g"
#define WFDB_PG_FREQ WFDB_FREQUENCY_PRINTF_MODIFIER "G"
#define WFDB_Se_FREQ WFDB_FREQUENCY_SCANF_MODIFIER "e"
#define WFDB_SE_FREQ WFDB_FREQUENCY_SCANF_MODIFIER "E"
#define WFDB_Sf_FREQ WFDB_FREQUENCY_SCANF_MODIFIER "f"
#define WFDB_Sg_FREQ WFDB_FREQUENCY_SCANF_MODIFIER "g"
#define WFDB_SG_FREQ WFDB_FREQUENCY_SCANF_MODIFIER "G"
#define WFDB_Pe_GAIN WFDB_GAIN_PRINTF_MODIFIER "e"
#define WFDB_PE_GAIN WFDB_GAIN_PRINTF_MODIFIER "E"
#define WFDB_Pf_GAIN WFDB_GAIN_PRINTF_MODIFIER "f"
#define WFDB_Pg_GAIN WFDB_GAIN_PRINTF_MODIFIER "g"
#define WFDB_PG_GAIN WFDB_GAIN_PRINTF_MODIFIER "G"
#define WFDB_Se_GAIN WFDB_GAIN_SCANF_MODIFIER "e"
#define WFDB_SE_GAIN WFDB_GAIN_SCANF_MODIFIER "E"
#define WFDB_Sf_GAIN WFDB_GAIN_SCANF_MODIFIER "f"
#define WFDB_Sg_GAIN WFDB_GAIN_SCANF_MODIFIER "g"
#define WFDB_SG_GAIN WFDB_GAIN_SCANF_MODIFIER "G"

/* getvec and getframe return a sample with a value of WFDB_INVALID_SAMPLE
   when the amplitude of a signal is undefined (e.g., the input is clipped or
   the signal is not available) and padding is disabled (see WFDB_GVPAD, below).
   WFDB_INVALID_SAMPLE is the minimum value for a 16-bit WFDB_Sample.  In
   a format 24 or 32 signal, this value will be near mid-range, but it should
   occur only rarely in such cases;  if this is a concern, WFDB_INVALID_SAMPLE
   can be redefined and the WFDB library can be recompiled. */
#define WFDB_INVALID_SAMPLE (-32768)

/* Array sizes
   Many older applications use the values of WFDB_MAXANN, WFDB_MAXSIG, and
   WFDB_MAXSPF to determine array sizes, but (since WFDB library version 10.2)
   there are no longer any fixed limits imposed by the WFDB library.
*/
#define WFDB_MAXANN 2   /* maximum number of input or output annotators */
#define WFDB_MAXSIG 32  /* maximum number of input or output signals */
#define WFDB_MAXSPF 4   /* maximum number of samples per signal per frame */
#define WFDB_MAXRNL 50  /* maximum length of record name */
#define WFDB_MAXUSL 50  /* maximum length of WFDB_siginfo `.units' string */
#define WFDB_MAXDSL 100 /* maximum length of WFDB_siginfo `.desc' string */

/* wfdb_fopen mode values (WFDB_anninfo '.stat' values) */
#define WFDB_READ 0      /* standard input annotation file */
#define WFDB_WRITE 1     /* standard output annotation file */
#define WFDB_AHA_READ 2  /* AHA-format input annotation file */
#define WFDB_AHA_WRITE 3 /* AHA-format output annotation file */
#define WFDB_APPEND 4    /* for output info files */

/* WFDB_siginfo '.fmt' values
FMT_LIST is suitable as an initializer for a static array; it lists all of
the legal values for the format field in a WFDB_siginfo structure.
 fmt    meaning
   0	null signal (nothing read or written)
   8	8-bit first differences
  16	16-bit 2's complement amplitudes, low byte first
  61	16-bit 2's complement amplitudes, high byte first
  80	8-bit offset binary amplitudes
 160	16-bit offset binary amplitudes
 212	2 12-bit amplitudes bit-packed in 3 bytes
 310	3 10-bit amplitudes bit-packed in 4 bytes
 311    3 10-bit amplitudes bit-packed in 4 bytes
  24	24-bit 2's complement amplitudes, low byte first
  32	32-bit 2's complement amplitudes, low byte first
*/
#define WFDB_FMT_LIST \
  { 0, 8, 16, 61, 80, 160, 212, 310, 311, 24, 32 }
#define WFDB_NFMTS 11 /* number of items in WFDB_FMT_LIST */

/* Default signal specifications */
#define WFDB_DEFFREQ 250.0 /* default sampling frequency (Hz) */
#define WFDB_DEFGAIN 200.0 /* default value for gain (adu/physical unit) */
#define WFDB_DEFRES 12     /* default value for ADC resolution (bits) */

/* calinfo '.caltype' values
WFDB_AC_COUPLED and WFDB_DC_COUPLED are used in combination with the pulse
shape definitions below to characterize calibration pulses. */
#define WFDB_AC_COUPLED 0   /* AC coupled signal */
#define WFDB_DC_COUPLED 1   /* DC coupled signal */
#define WFDB_CAL_SQUARE 2   /* square wave pulse */
#define WFDB_CAL_SINE 4     /* sine wave pulse */
#define WFDB_CAL_SAWTOOTH 6 /* sawtooth pulse */
#define WFDB_CAL_UNDEF 8    /* undefined pulse shape */

/* Structure definitions */
struct WFDB_siginfo {  /* signal information structure */
  char *fname;         /* filename of signal file */
  char *desc;          /* signal description */
  char *units;         /* physical units (mV unless otherwise specified) */
  WFDB_Gain gain;      /* gain (ADC units/physical unit, 0: uncalibrated) */
  WFDB_Sample initval; /* initial value (that of sample number 0) */
  WFDB_Group group;    /* signal group number */
  int fmt;             /* format (8, 16, etc.) */
  int spf;             /* samples per frame (>1 for oversampled signals) */
  int bsize;           /* block size (for character special files only) */
  int adcres;          /* ADC resolution in bits */
  int adczero;         /* ADC output given 0 VDC input */
  int baseline;        /* ADC output given 0 physical units input */
  long nsamp;          /* number of samples (0: unspecified) */
  int cksum;           /* 16-bit checksum of all samples */
};

struct WFDB_calinfo { /* calibration information structure */
  double low;         /* low level of calibration pulse in physical units */
  double high;        /* high level of calibration pulse in physical units */
  double scale;       /* customary plotting scale (physical units per cm) */
  char *sigtype;      /* signal type */
  char *units;        /* physical units */
  int caltype;        /* calibration pulse type (see definitions above) */
};

struct WFDB_anninfo { /* annotator information structure */
  char *name;         /* annotator name */
  int stat;           /* file type/access code (READ, WRITE, etc.) */
};

struct WFDB_ann {     /* annotation structure */
  WFDB_Time time;     /* annotation time, in sample intervals from
                         the beginning of the record */
  char anntyp;        /* annotation type (< ACMAX, see <wfdb/ecgcodes.h> */
  signed char subtyp; /* annotation subtype */
  unsigned char chan; /* channel number */
  signed char num;    /* annotator number */
  unsigned char *aux; /* pointer to auxiliary information */
};

struct WFDB_seginfo {            /* segment record structure */
  char recname[WFDB_MAXRNL + 1]; /* segment name */
  WFDB_Time nsamp;               /* number of samples in segment */
  WFDB_Time samp0;               /* sample number of first sample */
};

/* Composite data types */
typedef struct WFDB_siginfo WFDB_Siginfo;
typedef struct WFDB_calinfo WFDB_Calinfo;
typedef struct WFDB_anninfo WFDB_Anninfo;
typedef struct WFDB_ann WFDB_Annotation;
typedef struct WFDB_seginfo WFDB_Seginfo;

/* Dynamic memory allocation macros. */
#define MEMERR(P, N, S)                                         \
  do {                                                          \
    wfdb_error("WFDB: can't allocate (%lu*%lu) bytes for %s\n", \
               (unsigned long)N, (unsigned long)S, #P);         \
    if (wfdb_me_fatal()) exit(1);                               \
  } while (0)
#define SFREE(P) \
  do {           \
    if (P) {     \
      free(P);   \
      P = 0;     \
    }            \
  } while (0)
#define SUALLOC(P, N, S)                                                      \
  do {                                                                        \
    size_t WFDB_tmp1 = (N), WFDB_tmp2 = (S);                                  \
    if (WFDB_tmp1 == 0 || WFDB_tmp2 == 0) WFDB_tmp1 = WFDB_tmp2 = 1;          \
    if (!(P = calloc(WFDB_tmp1, WFDB_tmp2))) MEMERR(P, WFDB_tmp1, WFDB_tmp2); \
  } while (0)
#define SALLOC(P, N, S)   \
  do {                    \
    SFREE(P);             \
    SUALLOC(P, (N), (S)); \
  } while (0)
#define SREALLOC(P, N, S)                                         \
  do {                                                            \
    size_t WFDB_tmp1 = (N), WFDB_tmp2 = (S);                      \
    if (!(P = ((WFDB_tmp1 == 0 || WFDB_tmp2 == 0)                 \
                   ? realloc(P, 1)                                \
                   : ((WFDB_tmp1 > (size_t)-1 / WFDB_tmp2)        \
                          ? 0                                     \
                          : realloc(P, WFDB_tmp1 * WFDB_tmp2))))) \
      MEMERR(P, WFDB_tmp1, WFDB_tmp2);                            \
  } while (0)
#define SSTRCPY(P, Q)                             \
  do {                                            \
    const char *WFDB_tmp = (Q);                   \
    if (WFDB_tmp) {                               \
      SALLOC(P, (size_t)strlen(WFDB_tmp) + 1, 1); \
      strcpy(P, WFDB_tmp);                        \
    }                                             \
  } while (0)

// Produces an error message
void wfdb_error(std::string_view);
// Produces the last error message
std::string wfdberror();
// Suppresses WFDB library error messages
void wfdbquiet();
// Enables WFDB library error messages
void wfdbverbose();

#endif  // WFDB_LIB_WFDB_H_

