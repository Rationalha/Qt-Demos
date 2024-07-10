#include "ttkgiflabelwidget.h"

#include <QTimer>
#include <QPainter>

#define GIF_BALLON_WHITE        35
#define GIF_CICLE_BLUE          58
#define GIF_RICE_FONT_WHITE     26
#define GIF_RICE_FONT_BLACK_BIG 42
#define GIF_RICE_FONT_BLACK     16
#define GIF_HOURGLASS_WHITE     38
#define GIF_RADIO_BLUE          14
#define GIF_CHECK_BLUE          93
#define GIF_RECORD_RED          30
#define GIF_CLOSE_WHITE_WIDTH   350
#define GIF_CLOSE_WHITE_HEIGHT  50

TTKGifLabelWidget::TTKGifLabelWidget(QWidget *parent)
    : QLabel(parent)
{
    m_index = -1;
    m_isRunning = false;
    m_infinited = true;

    setFixedSize(GIF_CICLE_BLUE, GIF_CICLE_BLUE);

    m_timer = new QTimer(this);
    m_timer->setInterval(100);
    connect(m_timer, SIGNAL(timeout()), SLOT(timeout()));
}

TTKGifLabelWidget::TTKGifLabelWidget(Type type, QWidget *parent)
    : TTKGifLabelWidget(parent)
{
    setType(type);
}

TTKGifLabelWidget::~TTKGifLabelWidget()
{
    delete m_timer;
}

void TTKGifLabelWidget::setType(Type type)
{
    switch(m_type = type)
    {
        case Gif_Ballon_White: setFixedSize(GIF_BALLON_WHITE, GIF_BALLON_WHITE); break;
        case Gif_Cicle_Blue: setFixedSize(GIF_CICLE_BLUE, GIF_CICLE_BLUE); break;
        case Gif_Rice_Font_White: setFixedSize(GIF_RICE_FONT_WHITE, GIF_RICE_FONT_WHITE); break;
        case Gif_Rice_Font_Black_Big: setFixedSize(GIF_RICE_FONT_BLACK_BIG, GIF_RICE_FONT_BLACK_BIG); break;
        case Gif_Rice_Font_Black: setFixedSize(GIF_RICE_FONT_BLACK, GIF_RICE_FONT_BLACK); break;
        case Gif_Hourglass_White: setFixedSize(GIF_HOURGLASS_WHITE, GIF_HOURGLASS_WHITE); break;
        case Gif_Radio_Blue: setFixedSize(GIF_RADIO_BLUE, GIF_RADIO_BLUE); break;
        case Gif_Check_Blue: setFixedSize(GIF_CHECK_BLUE, GIF_CHECK_BLUE); break;
        case Gif_Record_red: setFixedSize(GIF_RECORD_RED, GIF_RECORD_RED); break;
        case Gif_Close_White: setFixedSize(GIF_CLOSE_WHITE_WIDTH, GIF_CLOSE_WHITE_HEIGHT); break;
        default: break;
    }
}

TTKGifLabelWidget::Type TTKGifLabelWidget::getType() const
{
    return m_type;
}

void TTKGifLabelWidget::setInterval(int value)
{
    m_timer->setInterval(value);
}

int TTKGifLabelWidget::getInterval() const
{
    return m_timer->interval();
}

void TTKGifLabelWidget::setInfinited(bool s)
{
    m_infinited = s;
}

bool TTKGifLabelWidget::getInfinited() const
{
    return m_infinited;
}

void TTKGifLabelWidget::run(bool run)
{
    if(run)
    {
        show();
        start();
    }
    else
    {
        hide();
        stop();
    }
}

void TTKGifLabelWidget::start()
{
    m_timer->start();
    m_isRunning = true;
}

void TTKGifLabelWidget::stop()
{
    m_timer->stop();
    m_isRunning = false;
}

void TTKGifLabelWidget::timeout()
{
    ++m_index;
    switch(m_type)
    {
        case Gif_Ballon_White:
            {
                if(m_index == 40 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_ballon_white").copy(GIF_BALLON_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Cicle_Blue:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_cicle_blue").copy(GIF_CICLE_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Rice_Font_White:
            {
                if(m_index == 8 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_rice_font_white").copy(GIF_RICE_FONT_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Rice_Font_Black_Big:
            {
                if(m_index == 8 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_rice_font_black_big").copy(GIF_RICE_FONT_BLACK_BIG*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Rice_Font_Black:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_rice_font_black").copy(GIF_RICE_FONT_BLACK*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Hourglass_White:
            {
                if(m_index == 16 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_hourglass_white").copy(GIF_HOURGLASS_WHITE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Radio_Blue:
            {
                if(m_index == 10 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_radio_blue").copy(GIF_RADIO_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Check_Blue:
            {
                if(m_index == 22 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_check_blue").copy(GIF_CHECK_BLUE*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Record_red:
            {
                if(m_index == 5 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_record_red").copy(GIF_RECORD_RED*m_index, 0, width(), height());
                update();
                break;
            }
        case Gif_Close_White:
            {
                if(m_index == 12 && infinitedModeCheck())
                {
                    break;
                }

                m_renderer = QPixmap(":/gif/lb_close_white").copy(GIF_CLOSE_WHITE_WIDTH*m_index, 0, width(), height());
                update();
                break;
            }
        default: break;
    }
}

void TTKGifLabelWidget::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);

    QPainter painter(this);
    painter.drawPixmap(0, 0, m_renderer);
}

bool TTKGifLabelWidget::infinitedModeCheck()
{
    m_index = 0;
    if(!m_infinited)
    {
        stop();
        return true;
    }
    else
    {
        return false;
    }
}
