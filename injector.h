/* injector.h --- 
 * 
 * Filename: injector.h
 * Description: 
 * Author: stax
 * Maintainer: 
 * Created: ven nov 20 23:05:39 2009 (+0100)
 * Version: 
 * Last-Updated: lun. oct. 30 23:34:26 2017 (+0100)
 *           By: stax
 *     Update #: 25
 * URL: 
 * Keywords: 
 * Compatibility: 
 * 
 */

/* Commentary: 
 * 
 * 
 * 
 */

/* Change log:
 * 
 * 
 */

/* This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; see the file COPYING.  If not, write to
 * the Free Software Foundation, Inc., 51 Franklin Street, Fifth
 * Floor, Boston, MA 02110-1301, USA.
 */


#ifndef INJECTOR_H
#define INJECTOR_H

#include <QtGui>
#include "jack_engine.h"

class Injector : public QWidget
{
  Q_OBJECT
private:
  
  JackEngine _jack;
  QString _clientName;
  QString _confFile;
  QMenu *_menu;
  QSystemTrayIcon _trayIcon;
  QRect _geoMem;

  QVBoxLayout _layout;
  QGroupBox _jackGB;
  QPushButton _jackClientActivation;
  //QGroupBox _ampGB;
  QLabel _staxaudio;
  MidiInputBox _midiIn;

  QPushButton _addMixer;
  QPushButton _removeMixer;

  QTableWidget _mixerGrid;

  MidiLearnerDlg _midiLearner;

  QTimer _vuTimer;
  int _timerID;
  
  void setUpGui();

  void closeEvent(QCloseEvent*);

  bool loadConf();
  bool saveConf();

  void timerEvent(QTimerEvent *event);


private slots:
  void jackCtrlClicked();
  void jackStopped();
  void addMixerClicked();
  void removeMixerClicked();
  void handleMidiEvent(struct MidiEvent);
  void trayIconActivated(QSystemTrayIcon::ActivationReason);


public:
  Injector(QString clientName);
  ~Injector();

};

#endif

/* injector.h ends here */
